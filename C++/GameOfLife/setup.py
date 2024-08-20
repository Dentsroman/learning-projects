import subprocess
import json
import shutil
import argparse
import os


def build_compile_execute(config: str = "Debug", cores: str = "2", clean_start: bool = True):

    my_wd = os.getcwd()

    # Check if ext/ exists...if not, create it
    if not os.path.exists(my_wd + "/ext"):
        subprocess.run("mkdir ext", shell=True)
        
    subprocess.run("conan install . --output-folder=ext --build=missing") # Install dependencies via Conan 
        
    # Check if /out exists
    if not os.path.exists(my_wd + "/out"):
        subprocess.run("mkdir out", shell=True)
    elif clean_start:
        shutil.rmtree(my_wd + "/out")
        print(my_wd + "/out has been deleted")
        subprocess.run("mkdir out", shell=True)        
        
    commands = ["cmake -S . -B ./build"]
    commands.extend([
            f"cmake --build ./build --config {config} --parallel {cores}", ""
        ])
    
    for command in commands:
        try:
            subprocess.run(command, shell=True, check=True)
        except subprocess.CalledProcessError as e:
            print(f"Error executing command '{command}': {e}")
           

# Note that this does not mean you can't define the case_definition.cuh by yourself!
if __name__ == "__main__":
    
    filename = "Shlong"
    if filename == "" :
        parser = argparse.ArgumentParser(description='Give simulation case file name.')
        parser.add_argument('filename', type=str, help='the filename to read')
        args = parser.parse_args()

        filename = args.filename

    build_compile_execute()
                          