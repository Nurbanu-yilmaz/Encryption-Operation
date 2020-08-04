#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;

unsigned char Permute(unsigned char in) {
    
    unsigned char deneme = in;
    unsigned char sonuc = 0;
    unsigned char Xa, Xb, Xc, Xd, Xe, Xg, Xf, Xh; // The ones for logical and

    // in ->  98 = 0 1 1 0  0 0 1 0

    Xa = 128, Xb = 64, Xc = 32, Xd = 16, Xe = 8, Xf = 4, Xg = 2, Xh = 1;
    unsigned char a, b, c, d, e, f, g, h;
    // from -> to
    a = in << 1; // 6 -> 7
    Xa = Xa & a;
    deneme = Xa;
    for (int i = 0; i < 8; i++)
    {
        if ((deneme & (1 << 7-i)))
        {
            Xa << 1;
        }
        else
        {
            Xa << 0;
        }
    }

    
    b = in << 2;
    Xb = Xb & b;// 4 -> 6
    deneme = Xb;
    for (int i = 0; i < 8; i++)
    {
        if ((deneme & (1 << 7 - i)))
        {
            Xb << 1;
        }
        else
        {
            Xb << 0;
        }
    }

    c = in >> 2;
    Xc = Xc & c;// 7 -> 5
    deneme = Xc;
    for (int i = 0; i < 8; i++)
    {
        if ((deneme & (1 << 7 - i)))
        {
            Xc << 1;
        }
        else
        {
            Xc << 0;
        }
    }

    d = in >> 1;
    Xd = Xd & d;// 5 -> 4
    deneme = Xd;
    for (int i = 0; i < 8; i++)
    {
        if ((deneme & (1 << 7 - i)))
        {
            Xd << 1;
        }
        else
        {
            Xd << 0;
        }
    }

    e = in << 1;
    Xe = Xe & e;// 2 -> 3
    deneme = Xe;
    for (int i = 0; i < 8; i++)
    {
        if ((deneme & (1 << 7 - i)))
        {
            Xe << 1;
        }
        else
        {
            Xe << 0;
        }
    }

    f = in << 2;
    Xf = Xf & f;// 0 -> 2
    deneme = Xf;
    for (int i = 0; i < 8; i++)
    {
        if ((deneme & (1 << 7 - i)))
        {
            Xf << 1;
        }
        else
        {
            Xf << 0;
        }
    }

    g = in >> 2;
    Xg = Xg & g;// 3 -> 1
    deneme = Xg;
    for (int i = 0; i < 8; i++)
    {
        if ((deneme & (1 << 7 - i)))
        {
            Xg << 1;
        }
        else
        {
            Xg << 0;
        }
    }

    h = in >> 1;
    Xh = Xh & h;// 1 -> 0
    deneme = Xh;
    
    for (int i = 0; i < 8; i++)
    {
        if ((deneme & (1 << 7 - i)))
        {
            Xh << 1;
        }
        else
        {
            Xh << 0;
        }
    }

    sonuc = sonuc|Xa;
    sonuc = sonuc|Xb;
    sonuc = sonuc|Xc;
    sonuc = sonuc|Xd;
    sonuc = sonuc|Xe;
    sonuc = sonuc|Xf;
    sonuc = sonuc|Xg;
    sonuc = sonuc|Xh;

    deneme = sonuc;

    return deneme;

}

string editkey (string plain, string k) {
    
    string yeni;
    int lenpla = plain.length();
    int lenke = k.length();
    
    int value, mode;
    
    
    if (lenpla< lenke) {
        for(int i =0; i<lenpla; i++) {
            yeni += k[i];
            
        }
    }
  
    else { //kısa eşit
        value = lenpla/lenke;
        mode = lenpla % lenke;
    for(int i = 0; i< value; i++) {
        yeni +=k;
        
    }
    for ( int j =0; j< mode; j++) {
        yeni+= k[j];
        
    }
    }
    return yeni;
    
}

int main() {
    string key, plaintext;
    cout<< "*** Welcome to the Simple Data Encryption Application ***" << endl;
    
    cout<< "Please enter the encryption key: ";
    getline(cin, key);
  
    
    while(true) {
        cout<< "Please enter the plaintext to be encrypted: ";
        getline(cin, plaintext);
        
        string afterpermute, ciphertext;
        char bos;
        int lenkey = key.length();
        int lenplain = plaintext.length();
        
        
        for (int j =0; j<lenplain; j++) {
            bos = Permute(plaintext[j]);
            afterpermute += bos;
           }
        
        string edittedkey = editkey(afterpermute,key);
        
        for(int i =0; i<afterpermute.length(); i++) {
            bos =  afterpermute[i] ^ edittedkey[i];
            ciphertext += bos;
           }
        cout<< "Ciphertext: ";
        for(int i = 0; i< ciphertext.length(); i++){
            cout<< hex<< (int)(unsigned char)ciphertext.at(i);

        }
        cout<< endl<< endl;
    }
    return 0;
 

}
