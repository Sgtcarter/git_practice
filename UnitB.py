

#First Script


#String Type Test

'''
print("Please enter in a string:")
string = input("")
print(string.isupper())
print(string.isdigit())
print(string.isalpha())
'''

#Escape Characters with a string

haiku = "Type, type, type away.\nCompile. Run. Hip hip hooray!\n No error today!"
print(haiku)

#Slicing a string

quote = "And now for something completely different"
print(quote[0:6])
print(quote[-4:])
print(quote[14:16])
print(quote[0::2])
print(quote[::-1])

#Using string operators + and *

pattern1 = ".~*'"
pattern2 = pattern1 + pattern1[::-1]
print(pattern2 * 5)



# Second Script

SMALLCST = 9.20
MEDIUMCST = 8.52
LARGECST = 7.89

print("How many small boxes do you need?")
Small = int(input()) 

print("How many medium boxes do you need?")
Medium = int(input())

print("How many large boxes do you need?")
Large = int(input())

print('{} {:>5} {:>15} {:>10}'.format('SIZE', 'QTY', 'COST PER BOX', 'TOTALS'))
print('{} {:>3} {:>13} {:>12}'.format('Small', Small, SMALLCST, Small * SMALLCST))
print('{} {:>2} {:>13} {:>12}'.format('Medium', Medium, MEDIUMCST, round(Medium * MEDIUMCST, 2)))



