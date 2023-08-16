# Paranteze

***Link: https://www.infoarena.ro/problema/paranteze***

Șirbi just learned in a Silverlight course about round brackets "(, )" , square brackets "[, ]" and braces "{, }" . A string is correctly bracketed if it is constructed according to the rules:

- "correctly bracketed string" = "empty string"
- "correct bracketed string" = "(" + - "correct bracketed string" + ")"
- "correct bracketed string" = "[" + - "correct bracketed string" + "]"
- "correct bracketed string" = "{" + "correct bracketed string" + "}"
- "correct bracketed string" = "correct bracketed string" + "correct bracketed string"
### Requirement
As in any course, homework is given, and Ţirbi received the following problem: Given a string with N brackets, find the maximum length of a correctly bracketed sequence.

### Input data
The input file parentheses.in contains on the first line the natural number N , and on the next line a string with N parentheses.

### Output data
The output file brackets.out contains the maximum length of a correctly bracketed sequence.

### limitation
- 1 ≤ N ≤ 1 000 000
- For 50% of tests N ≤ 1,000

### Example 
paranteze.in	   
13   
{)([({})]([{}    
parentheze.out:   
6   
### Explanation
The correctly bracketed sequence is in bold.
{)( ***[({})]*** ([{}