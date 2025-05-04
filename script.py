# /* Platon Lukyanov st128133@student.spbu.ru
#  * Lab Work 2
# */

import os

def add_header(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    with open(file_path, 'w') as file:
        file.write("/* Platon Lukyanov st128133@student.spbu.ru\n * Lab Work 2\n */\n")
        file.writelines(lines)

def add_header_to_files(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".cpp") or file.endswith(".h"):
                add_header(os.path.join(root, file))

if __name__ == "__main__":
    add_header_to_files("./src")
    add_header_to_files("./include")
    add_header_to_files("./tests")