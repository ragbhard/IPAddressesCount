Problem Statement:

Given a file IP.txt consisting of millions of records separated by new line character, each line can be a valid IPv4/IPv6 or invalid string. The task is to verify if the record is IPv4/Pv6 or Invalid and output the count of the total as well as unique IPv4/IPv6 addresses.

Expected output:

Total IPv4 address count: 
Total IPv6 address count
Unique IPv4 address count: 
Unique IPv6 address count: 
Invalid IP address count:

Definitions of IPv4 address and IPv6 address:

- A valid IPv4 address is an IP in the form “a1.a2.a3.a4” where 0 ≤ ai ≤ 255 and ai should not have leading zeros.

- A valid IPv6 address is an IP in the form “a1:a2:a3:a4:a5:a6:a7:a8” where
ai is a hexadecimal string which may contain digits, lower-case alphabets - ‘a’ to ‘f’ and upper-case alphabets - ‘A’ to ‘F’. Leading zeros are allowed in ai. Also, 1 ≤ ai.length ≤ 4


Design/Approach:

1. Open the file containing the IP addresses, read line by line and store it into a string variable line.

Steps for verifying IPv4 address:

2. (a) Implement a function verifyIPv4() which does the following:
Count of occurrence of ‘.’ in the given record/line of the file and store it in variable cnt.
If the value of cnt is not equal to 3, then return false as it is not a valid IPv4 address. Otherwise, tokenize on the basis of the character ‘.’ and store the tokenized strings in a vector tokens.
Check if the size of tokens is equal to 4 or not. If not equal, return false.
Otherwise, traverse the vector and check each token value lies in the range [0, 255] and does not have leading 0s. If not, return false.
If all the conditions satisfies then the string is a valid IPv4, return TRUE from the function

Steps for verifying IPv6 address:

2. (b) Implement a function verifyIPv6() which does the following:
If the value of cnt is not equal to 3, then return false as it is not a valid IPv4 address. Otherwise, tokenize on the basis of the character ‘.’ and store the tokenized strings in a vector tokens.
Check if the size of tokens is equal to 8 or not. If not equal, return false.
Otherwise, traverse the vector, check that the length of each token  alue is in the range [1, 4] and it is a valid hexadecimal number. If not, then return false.
If all the conditions satisfies then the string is a valid IPv4, return TRUE from the function

3. Increment total_ipv4_count, total_ipv6_count or invalid_addr_count and also store the IPv4/IPv6 address into a std::set. This std::set will hold the unique IPv4/Ipv6 addresses. The size of std::set will give the unique Ipv4/Ipv6 address counts.

4. Output the following:
Total IPv4 address count: 
Total IPv6 address count
Unique IPv4 address count: 
Unique IPv6 address count: 
Invalid IP address count:

Time & Space Complexities:
Time Complexity of insertion in a unordered_Set which internally uses hashmap is O(n) and time complexity of functions verifyIPv4() and verifyIPv6() are also O(n). Space complexity is also O(n).

Time Complexity: O(n)
Space Complexity: O(n)

Unit Testing:

Ran the program and verified the IPv4/IPv6/invalid count values.
