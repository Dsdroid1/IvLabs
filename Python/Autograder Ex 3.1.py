hrs = input("Enter Hours:")
h = float(hrs)
rate=float(input("Enter rate"))
if h>40:
    pay=40*rate+(h-40)*rate*1.5
else:
    pay=h*rate
print(pay)
