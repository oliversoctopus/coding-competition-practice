"""
ID: oliver.11
LANG: PYTHON3
TASK: friday
"""

fin=open('friday.in', 'r')

n=int(fin.readline().strip())

months={'Jan': 31, 'Feb': 28, 'Mar': 31, 'Apr': 30, 'May': 31,
        'June': 30, 'July': 31, 'Aug': 31, 'Sep': 30,'Oct': 31,
        'Nov': 30, 'Dec': 31}

def leap_year(year_n):
    if year_n%4==0:
        if year_n%100==0:
            if year_n%400==0:
                return True
            return False
        return True
    return False

def year(year_n, start_day):
    is_leap=leap_year(year_n)
    days_of_week=[0]*7
    #end_year
    for month, days in months.items():
        if month=='Feb':
            if is_leap:
                days+=1
        days_of_week[start_day]+=1
        rem=(days+start_day)%7
        start_day=rem
    return [days_of_week, start_day%7]

start_day=0
final_results=[0]*7

for y in range(1900, 1900+n):
    results=year(y, start_day)
    start_day=results[1]
    for i in range(7):
        final_results[i]+=results[0][i]

days_str=''
for res in final_results:
    days_str+=str(res)
    days_str+=' '
days_str=days_str[:-1]+'\n'

fout=open('friday.out', 'w')
fout.write(days_str)
