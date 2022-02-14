from funcs import *

# Шляхи до файлів та їх назви
path = "text_file.txt"
new_path = "new_file.txt"

input_file(path)
new_file(path, new_path)

print("\nПочатковий файл:")
output_file(path)
print("\nНовий файл:")
output_file(new_path)
