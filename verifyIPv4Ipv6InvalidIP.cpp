#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
  
// This function verifies whether the input string is IPv4 or not
bool verifyIPv4(string s)
{
	// counting the occurence of '.'
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.')
            cnt++;
    }
  
    // If cnt != 3 then it is not a valid IPv6 Address
    if (cnt != 3)
        return false;
  
    vector<string> tokens;
    stringstream scheck(s);
    string midway;
  
    // Tokenizing on the basis of '.'
    while (getline(scheck, midway, '.')) {
        tokens.push_back(midway);
    }
  
    if (tokens.size() != 4)
        return false;
  
    // Verifying if all the tokenized strings lies in the range of [0, 255]
    for (int i = 0; i < tokens.size(); i++) {
        int value = 0;
		
		if (tokens[i] == "0")
            continue;
  
        if (tokens[i].size() == 0)
            return false;
  
        for (int j = 0; j < tokens[i].size(); j++) {
            if (tokens[i][j] > '9' || tokens[i][j] < '0')
                return false;
            value *= 10;
            value += tokens[i][j] - '0';
            if (value == 0)
                return false;
        }
  
        // checking the range of value
        if (value > 255 || value < 0)
            return false;
    } 
    return true;
}
  
// This function checks if the input string s is a valid hexadecimal number
bool checkHex(string s)
{
    int n = s.length();
  
    for (int i = 0; i < n; i++) {
        char ch = s[i];
  
        // return false for invalid characters
        if ((ch < '0' || ch > '9')
            && (ch < 'A' || ch > 'F')
            && (ch < 'a' || ch > 'f')) {
            return false;
        }
    }
    return true;
}
  
// This function verifies whether the input string is IPv4 or not
bool verifyIPv6(string s)
{
    // counting the occurence of ':'
    int cnt = 0;
  
    for (int i = 0; i < s.size();
         i++) {
        if (s[i] == ':')
            cnt++;
    }
  
    // If cnt != 7 then it is not a valid IPv6 Address
    if (cnt != 7)
        return false;
  
    vector<string> tokens;
    stringstream scheck(s);
    string midway;
  
    // Tokenizing on the basis of '.'
    while (getline(scheck, midway, ':')) {
        tokens.push_back(midway);
    }
  
    if (tokens.size() != 8)
        return false;
  
    // verify all the tokenized values are hexadecimal format
    for (int i = 0; i < tokens.size(); i++) {
        int len = tokens[i].size();
        if (!checkHex(tokens[i])
            || len > 4 || len < 1) {
            return false;
        }
    }
    return true;
} 

int main()
{
    string filename("IP.txt");
	string line;
	
	int total_ipv4_count = 0;
    int total_ipv6_count = 0;
    int invalid_addr_count = 0;
	
    set<string> ipv4;
    set<string> ipv6;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line)){
        // Verifying if the string is IPv4
        if (verifyIPv4(line)) {
            total_ipv4_count++;
            ipv4.insert(line);
        }
  
        // Verifying if the string is IPv6
        else if (verifyIPv6(line)) {
            total_ipv6_count++;
            ipv6.insert(line);
        }
  
        // Otherwise, it is a invalid IP address
        else {
            invalid_addr_count++;
        }
    }
    
    cout<<"Total IPv4 address count: " << total_ipv4_count << endl;
    cout<<"Total IPv6 address count: " << total_ipv6_count << endl;
    cout<<"Unique IPv4 address count: " << ipv4.size() << endl;
    cout<<"Unique IPv6 address count: " << ipv6.size() << endl;
    cout<<"Invalid IP address count: " << invalid_addr_count << endl;
    
    return 0;
}