'''
Lance Sunzeri
CIS 41A   Fall 2019
Unit B take-home assignment
'''
#First Script

#String Type Test
print("Please enter in a string:")
string = input("")
print(string.isupper())
print(string.isdigit())
print(string.isalpha())

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
print('{} {:>3} {:>13} {:>12}'.format('Small', Small, SMALLCST, round(Small * SMALLCST, 3)))
print('{} {:>2} {:>13} {:>12}'.format('Medium', Medium, MEDIUMCST, round(Medium * MEDIUMCST, 3)))
print('{} {:>3} {:>13} {:>12}'.format('Large', Large, LARGECST, round(Large * LARGECST, 3)))

'''
Execution Results:
Please enter in a string:                                                                                                                                                            
ABCD123                                                                                                                                                                              
True                                                                                                                                                                                 
False                                                                                                                                                                                
False                                                                                                                                                                                
Type, type, type away.                                                                                                                                                               
Compile. Run. Hip hip hooray!                                                                                                                                                        
 No error today!                                                                                                                                                                     
And no                                                                                                                                                                               
rent                                                                                                                                                                                 
me                                                                                                                                                                                   
Adnwfrsmtigcmltl ifrn                                                                                                                                                                
tnereffid yletelpmoc gnihtemos rof won dnA                                                                                                                                           
.~*''*~..~*''*~..~*''*~..~*''*~..~*''*~. 
#Test 1
How many small boxes do you need?                                                                                                                                                    
10                                                                                                                                                                                   
How many medium boxes do you need?                                                                                                                                                   
9                                                                                                                                                                                    
How many large boxes do you need?                                                                                                                                                    
8                                                                                                                                                                                    
SIZE   QTY    COST PER BOX     TOTALS                                                                                                                                                
Small  10           9.2         92.0                                                                                                                                                 
Medium  9          8.52        76.68                                                                                                                                                 
Large   8          7.89        63.12

#Test 2
How many small boxes do you need?                                                                                                                                                    
5                                                                                                                                                                                    
How many medium boxes do you need?                                                                                                                                                   
10                                                                                                                                                                                   
How many large boxes do you need?                                                                                                                                                    
15                                                                                                                                                                                   
SIZE   QTY    COST PER BOX     TOTALS                                                                                                                                                
Small   5           9.2         46.0                                                                                                                                                 
Medium 10          8.52         85.2                                                                                                                                                 
Large  15          7.89       118.35 
'''
