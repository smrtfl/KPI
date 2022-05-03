import pickle
import os

schedule = {
    'name': [],
    'time': {'hours': [], 'minutes': []},
    'duration': []}

clocks = {'hh': ' ',
          'mm': ' '}

spare_time = {'start_time': {'hh': [], 'mm': []},
              'end_time': {'hh': [], 'mm': []},
              'time': {'hh': " ", 'mm': " "}}

def create_schedule(file_path):
    if not os.path.exists('todo_list.pickle'):
        print("-----CREATE YOUR SCHEDULE-----")
        schedule_data = schedule
    else:
        read_data(file_path)
        print("\n-----ADD NEW ACTIVITIES-----")

        with open(file_path, 'rb') as f:
            schedule_data = pickle.load(f)

        os.remove(file_path)

    add = 1
    while add:
        add_str = input("\nAdd an activity? [y] ")
        if add_str == 'y' or add_str == 'Y':
            add = 1
        else:
            add = 0

        if add:  # adding new activity
            schedule_data['name'].append(input("Enter name: "))
            schedule_data['time']['hours'].append(input("Enter start hour (hh): "))
            schedule_data['time']['minutes'].append(input("minute (mm): "))
            schedule_data['duration'].append(input("Enter duration: "))

    with open(file_path, 'wb') as f:
        pickle.dump(schedule_data, f)  # pickling activity to file

    sort_schedule(file_path)

def sort_schedule(fp):
    with open(fp, 'rb') as f:
        schedule_data = pickle.load(f)

    os.remove(fp)

    with open("temp.pickle", 'wb') as temp:
        pickle.dump(schedule_data, temp)

        min_list = []

        for i in range(len(schedule_data['name'])):
            min_list.append(int(schedule_data['time']['hours'][i]) * 60 + int(schedule_data['time']['minutes'][i]))

        for i in range(len(min_list)):
            for j in range(0, len(min_list) - i - 1):
                if min_list[j] > min_list[j + 1]:
                    temp = min_list[j]
                    min_list[j] = min_list[j + 1]
                    min_list[j + 1] = temp

        with open("temp.pickle", 'rb'):
            final_data = {'name': [],
                          'time': {'hours': [], 'minutes': []},
                          'duration': []}
            for i in range(len(min_list)):
                for j in range(len(schedule_data['name'])):
                    if int(schedule_data['time']['hours'][j]) * 60 + int(schedule_data['time']['minutes'][j]) == min_list[i]:
                        final_data['name'].append(schedule_data['name'][j])
                        final_data['time']['hours'].append(schedule_data['time']['hours'][j])
                        final_data['time']['minutes'].append(schedule_data['time']['minutes'][j])
                        final_data['duration'].append(schedule_data['duration'][j])

        with open(fp, 'wb') as f:
            pickle.dump(final_data, f)

    os.remove("temp.pickle")

def read_data(file_path):
    if os.path.exists("todo_list.pickle") or os.path.exists("spare_time.pickle"):
        with open(file_path, 'rb') as f:
            if file_path == "todo_list.pickle":  # output for to-do list
                print("-----SCHEDULE FOR TODAY-----")

                out_data = pickle.load(f)

                for i in range(len(out_data['name'])):
                    print("%s %s:%s %s min" % (
                        out_data['name'][i],
                        out_data['time']['hours'][i], out_data['time']['minutes'][i],
                        out_data['duration'][i]))
            else:  # output for info about spare time
                out_st = pickle.load(f)
                print("\n-----SPARE TIME-----")
                for i in range(len(out_st['start_time']['hh'])):
                    out_st['start_time']['hh'][i] = double_null(out_st['start_time']['hh'][i])
                    out_st['start_time']['mm'][i] = double_null(out_st['start_time']['mm'][i])
                    out_st['end_time']['hh'][i] = double_null(out_st['end_time']['hh'][i])
                    out_st['end_time']['mm'][i] = double_null(out_st['end_time']['mm'][i])

                    print("%s:%s - %s:%s" % (out_st['start_time']['hh'][i], out_st['start_time']['mm'][i],
                                             out_st['end_time']['hh'][i], out_st['end_time']['mm'][i]))
                print("Total: %s hours %s min" % (out_st['time']['hh'], out_st['time']['mm']))
    else:
        print("Can't open '%s' file :(" % file_path)

def double_null(dn): # doubling null func
    if dn == "0":
        dn = ''.join("00")

    return dn

def closest_activity(file_path):
    current = clocks

    diff_min = 1440

    current['hh'] = input("\n-----CLOSEST ACTIVITY-----\nEnter current hour (hh): ")
    current['mm'] = input("Enter current minute (mm): ")

    with open(file_path, 'rb') as f:
        closest = pickle.load(f) # getting data from file

        for i in range(len(closest['name'])): # calculations for each activity
            if int(closest['time']['hours'][i]) > int(current['hh']) or (
                    int(closest['time']['hours'][i]) == int(current['hh']) and int(closest['time']['minutes'][i]) > int(current['mm'])):
                next_diff_min = (int(closest['time']['hours'][i]) * 60) - (int(current['hh']) * 60) + int(
                    closest['time']['minutes'][i]) - int(current['mm'])
                if 0 <= next_diff_min <= diff_min:
                    diff_min = next_diff_min

        for i in range(len(closest['name'])): # output the closest activity
            next_diff_min = (int(closest['time']['hours'][i]) * 60) - (int(clocks['hh']) * 60) + int(
                closest['time']['minutes'][i]) - int(clocks['mm'])
            if next_diff_min == diff_min:
                print("\nClosest activity is '%s' at %s:%s" % (
                    closest['name'][i], closest['time']['hours'][i], closest['time']['minutes'][i]))


def rest_info(file_path, new_fp):
    info_st = spare_time

    rest_min = 0
    prev_min = 780
    with open(file_path, 'rb') as f:
        schedule_data = pickle.load(f)
        for i in range(len(schedule_data['name'])):
            curr_min = (int(schedule_data['time']['hours'][i]) * 60) + int(schedule_data['time']['minutes'][i])

            if i == len(schedule_data['name']) - 1:
                for j in range(prev_min, 1440):
                    if j < curr_min or j >= curr_min + int(schedule_data['duration'][i]):
                        rest_min += 1

                # write data to dict (same below)
                info_st['start_time']['hh'].append(str(prev_min // 60))
                info_st['start_time']['mm'].append(str(prev_min % 60))
                info_st['end_time']['hh'].append(str(curr_min // 60))
                info_st['end_time']['mm'].append(str(curr_min % 60))

                prev_min = curr_min + int(schedule_data['duration'][i])

                if prev_min < 1440:
                    info_st['start_time']['hh'].append(str(prev_min // 60))
                    info_st['start_time']['mm'].append(str(prev_min % 60))
                    info_st['end_time']['hh'].append("23")
                    info_st['end_time']['mm'].append("59")

            else:
                for j in range(prev_min, curr_min + int(schedule_data['duration'][i])):
                    if j < curr_min:
                        rest_min += 1
                if curr_min >= 780:
                    info_st['start_time']['hh'].append(str(prev_min // 60))
                    info_st['start_time']['mm'].append(str(prev_min % 60))
                    info_st['end_time']['hh'].append(str(curr_min // 60))
                    info_st['end_time']['mm'].append(str(curr_min % 60))

                if curr_min + int(schedule_data['duration'][i]) >= 780:
                    prev_min = curr_min + int(schedule_data['duration'][i])

    info_st['time']['hh'] = (str(rest_min // 60))
    info_st['time']['mm'] = (str(rest_min % 60))

    with open(new_fp, 'wb') as f:
        pickle.dump(info_st, f)
