import subprocess
import sys
import glob, os

if len(sys.argv) != 2:
    print("Please input the exe to run as a argument")
    quit()

os.chdir(".")
for file in glob.glob("*.in"):
    with open (file, "r") as inputFile:
        lines = inputFile.read()
        proc = subprocess.Popen(sys.argv[1], stdout=subprocess.PIPE, stdin=subprocess.PIPE)
        (r, a) = proc.communicate(input=bytes(lines, 'utf-8'))
        res = str(r, 'utf-8').replace('\r', '')
        with open (file[:-3]+".ans", "r") as expected:
            print("\n--------NEXT FILE--------- \n")
            expectedRes = expected.read().replace('\r', '')
            if res != expectedRes:
                print("Failed on: " + file)
                print("input:")
                print(lines)
                print("expected:")
                print(expectedRes)
                print("got:")
                print(res)
            else:
                print("Success on: " + file)