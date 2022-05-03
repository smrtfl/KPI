from funcs import *

path = "todo_list.pickle"
new_path = "spare_time.pickle"

create_schedule(path)
read_data(path)

closest_activity(path)

rest_info(path, new_path)
read_data(new_path)
