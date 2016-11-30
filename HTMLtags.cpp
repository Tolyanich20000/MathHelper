#include "stdafx.h" 
#include "HTMLtags.h" 

using namespace std;
using namespace tags;

int pairedtags::is_close(int poz, int ind) {
		if(poz==-1){
		return -1;
		}
		string buf;
		bool ex = true;
		while (poz < code.size()) {
			poz++;
			int j = poz;
			if (code[poz] == '<') {
				buf.clear();

				do{
					buf.push_back(code[poz]);
					poz++;
				}while (code[poz-1] != '>' && poz < code.size());

					while (j < 109 && buf != PairedMass[j]) {
						j++;
						if (j < 109 && buf == PairedMass[j]) {
							return is_close(poz,j); ex = true;
						}
					};
					if (buf == ClosedPairedMass[ind])
						return poz;
					else
						return -1;
					j = 0;
					while (j < 19 && buf != singlemass[j]) {
						j++;
						if (j < 19 && buf == singlemass[j]) {
							ex = true;
						}
					};
					j = 0;
					while (j < 19 && buf != singleclosedmass[j]) {
						j++;
						if (j < 19 && buf == singleclosedmass[j]) {
							ex = true;
						}
					};
					if (!ex) {
						cout << buf <<"Incorect!"<<endl;
						return -1;
					}
			}
		}
		return -1;
	};



void TagsTest(string adres)
{
	string buf;
	ifstream HTMLcode(adres);
	if(HTMLcode.is_open()){
	while (HTMLcode >> buf)
		code.append(buf);
	}
	else{
		cout<<"Incorect adres!";
		_gettch();
		exit(0);
	}
	HTMLcode.close();
	int i = 0;
	while (i < code.size()) {
		if (code[i] == '<') {
			buf.clear();
			do {
				buf.push_back(code[i]);
				i++;
			}while (code[i-1] != '>' && i < code.size());
			int j = 0,nom=0,ind=0;
			bool ex=false;

			while (j < 19 && buf != singlemass[j]) {
				j++;
				if (j < 19 && buf == singlemass[j]){
					nom = 1; ex = true;ind=j; 
				} 
			};
			j = 0;
			while (j < 19 && buf != singleclosedmass[j]) {
				j++;
				if (j < 19 && buf == singleclosedmass[j]){
					nom = 2; ex = true;ind=j; 
				}
			};
			j = 0;
			while (j < 109 && buf != PairedMass[j]) {
				j++; 
				if (j < 109 && buf == PairedMass[j]) {
					nom = 3; ex = true;ind=j; 
				}
			};
			j = 0;
			while (j < 109 && buf != ClosedPairedMass[j]) {
				j++; 
				if (j < 109 && buf == ClosedPairedMass[j]){
					nom = 4; ex = true;ind=j;  
				}
			};
			if (!ex) {
				cout << buf << " Incorect!" << endl;
			}
			switch (nom)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				i = pairedtags::is_close(i,ind);
				if(i==-1){
				cout<<buf<<" Unclosed!";
				}
				break;
			case 4:
				cout << buf << " Incorect Closed tag!" << endl;
				break;
			default:
				break;
			}
		}
	}
	cout<<"Corect!";
}