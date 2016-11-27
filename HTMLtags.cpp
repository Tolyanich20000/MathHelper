#pragma once 
#include "stdafx.h" 
#include "HTMLtags.h" 
#include <fstream> 
#include <iostream> 
#include <string> 

using namespace std;

int pairedtags::is_close(int poz, int ind) {
		string buf;
		bool ex = true;
		while (poz < code.size()) {
			poz++;
			int j = poz;
			if (code[poz] == '<') {
				buf = "";
				while (code[poz - 1] != '>' && poz < code.size()) {
					buf.push_back(code[poz]);
					poz++;
					while (j < 109 && buf != PairedMass[j]) {
						j++;
						if (j < 109 && buf == PairedMass[j]) {
							return is_close(poz,j); ex = true;
						}
					};
					j = poz;
					while (j < 109 && buf != ClosedPairedMass[j]) {
						j++;
						if (j < 109 && buf == ClosedPairedMass[j]) {
							ex = true;
							if (buf == ClosedPairedMass[ind])
								return poz;
							else
								return -1;
						}
					};
					j = poz;
					while (j < 19 && buf != singlemass[j]) {
						j++;
						if (j < 19 && buf == singlemass[j]) {
							ex = true;
						}
					};
					j = poz;
					while (j < 19 && buf != singleclosedmass[j]) {
						j++;
						if (j < 19 && buf == singleclosedmass[j]) {
							ex = true;
						}
					};
					if (!ex) {
						cout << buf <<" Incorect!"<<endl;
						return -1;
					}
				}
			}
		}
	};



void TagsTest(string adres)
{
	string buf;
	ifstream HTMLcode;
	HTMLcode.open(adres);
	while (HTMLcode >> buf)
		code.append(buf);
	HTMLcode.close();
	int i = 0;
	while (i < code.size()) {
		if (code[i] == '<') {
			buf = "";
			while (code[i-1] != '>' && i < code.size()) {
				buf.push_back(code[i]);
				i++;
			}
			int j = i,nom=0;
			bool ex=false;

			while (j < 19 && buf != singlemass[j]) {
				j++;
				if (j < 19 && buf == singlemass[j]){
					nom = 1; ex = true; 
				} 
			};
			j = i;
			while (j < 19 && buf != singleclosedmass[j]) {
				j++;
				if (j < 19 && buf == singleclosedmass[j]){
					nom = 2; ex = true; 
				}
			};
			j = i;
			while (j < 109 && buf != PairedMass[j]) {
				j++; 
				if (j < 109 && buf == PairedMass[j]) {
					nom = 3; ex = true; 
				}
			};
			j = i;
			while (j < 109 && buf != ClosedPairedMass[j]) {
				j++; 
				if (j < 109 && buf == ClosedPairedMass[j]){
					nom = 4; ex = true; 
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
				i = pairedtags::is_close(i,j);
				break;
			case 4:
				cout << buf << " Incorect Closed tag!" << endl;
				break;
			default:
				break;
			}
		}
	}
}
