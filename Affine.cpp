#include<bits/stdc++.h>
using namespace std;
int arr_key[100000];
int modInverse(int A, int M)
{
    for (int X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
}
string encrypt(string plain_text, int key1,int key2)
{
    string cipher_text = "";

    int n = plain_text.size();
    for(int i = 0; i < n; i++){
        char c = (((plain_text[i]-'a')*key1)+key2)%26 + 'a';
        cipher_text += c;
    }
    return cipher_text;
}
string decrypt(string cipher_text, int key1,int key2)
{
    string plain_text = "";
    int n = cipher_text.size();
    int mod = modInverse(key1,26);
    for(int i = 0; i < n; i++){
        int x = cipher_text[i]-'a' - key2;
        x = (x+26)%26;
        x *= mod;
        x %= 26;

        plain_text += (x+'a');
    }
    return plain_text;
}
int main()
{
    //freopen("inp.txt","r", stdin);
    //freopen("out.txt","w", stdout);
	string plain_text;
	int key1, key2;
	cin >> plain_text >> key1 >> key2;
	int n = plain_text.size();
	if(__gcd(key1,26)!=1){
        cout << "No Multiplicative inverse of key 1";
        return 0;
	}
	string cipher_text = encrypt(plain_text,key1,key2);
	for(int i = 0; i < plain_text.size(); i++){
		cipher_text[i] = toupper(cipher_text[i]);
	}
	cout << cipher_text << endl;
	for(int i = 0; i < plain_text.size(); i++){
		cipher_text[i] = tolower(cipher_text[i]);
	}
	plain_text = decrypt(cipher_text,key1, key2);
	cout << plain_text << "\n";

	return 0;
}
///attackistoday 12
