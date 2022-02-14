def input_file(file_path):
    print("Press CTRL + F2 to stop. Input text in file:")

    text = []
    while True:
        try:
            line = input()
            text.append(line)
        except KeyboardInterrupt:
            break

    new_text = '\n'.join(text)

    file = open(file_path, 'w')
    file.write(new_text)
    file.close()

def new_file(file_path, new_fp):
    file = open(file_path)
    text = file.read()

    lines = text.split("\n")
    new_lines = []
    for line_number in range(len(lines)):
        if len(lines[line_number]) > 0:
            words = lines[line_number].split()
            last_word = words[len(words) - 1]

            lines[line_number] = "'" + last_word[0] + "' - " + lines[line_number]
        new_lines.append(lines[line_number])

    new_text = '\n'.join(new_lines)
    file = open(new_fp, 'w')
    file.write(new_text)
    file.close()

def output_file(file_path):
    file = open(file_path)
    print(file.read())
    file.close()
