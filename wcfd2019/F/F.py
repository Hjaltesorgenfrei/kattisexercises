import datetime
import calendar

k = ["JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"]
w = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]

n = input().split()
day = int(n[0])
month = k.index(n[1]) + 1
givenweekday = w.index(input()) + 1
y = 2020
d = datetime.datetime(y, 1, 1)
wd = datetime.datetime(y,month, day)
caweda = (wd.weekday() + d.weekday() + givenweekday) % 7
if wd <= datetime.datetime(y, 2, 29):
    if caweda == 5:
        print("TGIF")
    else:
        print(":(")
elif caweda == 5 or caweda == 4:
    print("not sure")
else:
    print(":(")