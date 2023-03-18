#include<bits/stdc++.h>
using namespace std;
string encryption(string s, int key)
{
    for(int i = 0; i < s.length(); i++){
        int temp = s[i]-'a';
        s[i] = (s[i]-'a' + key)%26+'a';
        key = temp;
    }
    return s;
}
string decryption(string s, int key)
{
    for(int i = 0; i < s.length(); i++){
        s[i] = (s[i] - key - 'a'+26)%26 + 'a';
        key = s[i]-'a';
    }
    return s;
}
int main()
{
	//freopen("inp.txt","r",stdin);
	//freopen("out.txt","w",stdout);

    string plain_text;
    int key;
    cin >> plain_text >> key;
    string cipher_text = encryption(plain_text,key);
    cout<< cipher_text<<"\n";
    int  n = plain_text.length();
    for(int i = 0; i < n; i++){
        cipher_text[i] = toupper(cipher_text[i]);
    }
    cout << "ciphertext: ";
    cout << cipher_text << "\n";
    for(int i = 0; i < n; i++){
        cipher_text[i] = tolower(cipher_text[i]);
    }
    plain_text = decryption(cipher_text,key);
    cout << "plaintext: ";
    cout << plain_text << "\n";

    return 0;
}
