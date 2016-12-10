#include "stdafx.h" 
#include "HTMLtags.h"

#define PairSIZE 105
#define SingleSIZE 21

using namespace std;
using namespace tags;

string ClosedPairedMass[] = { "</comment>","</a>","</abbr>", 
"</acronym>","</b>",  		 "</canvas>",  "</datagrid>", 
"</address>",			  	 "</caption>", "</datalist>", 
"</applet>" ,				 "</center>",  "</datatemplate>",
			 "</bdo>", 		 "</cite>",    "</dd>", 
"</article>","</big>",  	 "</code>",    "</del>", 
"</aside>",  "</blockquote>",			   "</details>", 
"</audio>",  "</body>", 	 "</colgroup>","</dialog>",  
							 "</command>", "</dir>",
			 "</button>", 				   "</div>", 
										   "</dfn>", 
										   "</dl>", 
										   "</dt>", 
"</em>", 		 "</fieldset>","</h1>",  	"</i>", 				 "</mark>", 
			 	 "</figure>",  "</h2>",		"</iframe>", "</kbd>", 	 "</map>", 
"</eventsource>","</font>",    "</h3>",				 	 "</label>", "</menu>", 
				 "</footer>",  "</h4>",					 "</legend>",  
				 "</form>",    "</h5>",		"</ins>", 	 "</li>", 	 "</meter>",
				 "</frame>",   "</h6>", 	"</isindex>",
				 "</frameset>","</head>",  
							   "</header>", 
							   "</html>", 
"</nav>", 	  "</object>" , "</p>", 	  "</s>", 	   "</table>", 	 "</u>", 
"</nest>", 	  "</ol>", 					  "</samp>",   "</tbody>", 	 "</ul>", 
"</noframes>","</optgroup>","</pre>",  	  "</script>", "</td>", 	 "</var>", 
"</noscript>","</option>",  "</progress>","</section>", 			 "</video>",
			  "</output>", 	"</q>", 	  "</select>", "</tfoot>", 	 "</xmp>"   
							"</rule>", 	  "</small>",  "</th>", 
										  "</svg>",	   "</thead>", 
										  "</span>",   "</time>", 
										  "</strike>", "</title>", 
 										  "</strong>", "</tr>", 
										  "</style>",  "</tt>", 
										  "</sub>", 
										  "</sup>", 
};
string PairedMass[] = { "<comment>","<a>","<abbr>", 
"<acronym>","<b>",  		 "<canvas>",  "<datagrid>", 
"<address>",			  	 "<caption>", "<datalist>", 
"<applet>" ,			 "<center>",  "<datatemplate>",
		 	"<bdo>", 		 "<cite>",    "<dd>", 
"<article>","<big>",  	 "<code>",    "<del>", 
"<aside>",  "<blockquote>",			   "<details>", 
"<audio>",  "<body>", 	 "<colgroup>","<dialog>",  
							 "<command>", "<dir>",
			 "<button>", 				   "<div>", 
										   "<dfn>", 
										   "<dl>", 
										   "<dt>", 
"<em>", 		 "<fieldset>","<h1>",  	"<i>", 				 "<mark>", 
			 	 "<figure>",  "<h2>",		"<iframe>", "<kbd>", 	 "<map>", 
"<eventsource>","<font>",    "<h3>",				 	 "<label>", "<menu>", 
				 "<footer>",  "<h4>",					 "<legend>", 
				 "<form>",    "<h5>",		"<ins>", 	 "<li>", 	 "<meter>",
				 "<frame>",   "<h6>", 	"<isindex>",
				 "<frameset>","<head>",  
							   "<header>", 
							   "<html>", 
"<nav>", 	  "<object>" , "<p>", 	  "<s>", 	   "<table>", 	 "<u>", 
"<nest>", 	  "<ol>", 				  "<samp>",   "<tbody>", 	 "<ul>", 
"<noframes>","<optgroup>","<pre>",  	  "<script>", "<td>", 	 "<var>", 
"<noscript>","<option>",  "<progress>","<section>",				"<video>",
			  "<output>", 	"<q>", 	  "<select>", "<tfoot>", 	 "<xmp>"   
							"<rule>", 	  "<small>",  "<th>", 
										  "<svg>",	  "<thead>", 
										  "<span>",   "<time>", 
										  "<strike>", "<title>", 
 										  "<strong>", "<tr>", 
										  "<style>",  "<tt>", 
										  "<sub>", 
										  "<sup>",
};
string singlemass[] = { "<!DOCTYPE>","<area>","<base>","<basefont>","<bgsound>","<br>","<col>","<command>","<embed>","<hr>","<img>","<input>","<isindex>","<keygen>","<link>","<meta>","<param>","<source>","<track>","<wbr>" };
string code;

void pairedtags::TagsTest(string adres)
{
	vector<pair<string,int>> incor;
	int pairs[PairSIZE] = { 0 };
	int fails[PairSIZE]={0};
	string buf;
	char scan[1000000];
	bool fl = false;
	ifstream HTMLcode;
	HTMLcode.open(adres);
	if (HTMLcode.is_open()){
		code.clear();
		while (HTMLcode.getline(scan,1000000))
			code.append(scan);
	}
	else{
		cout << "Incorect adres!" << endl;
		_gettch();
		return;
	}
	HTMLcode.close();
	//*********************************************
	long long int i = 0;
	while (i < code.size()) {

		if (code[i] == '<' && code[i+1] != '!' && code[i+2] != '-' && code[i+3] != '-') {
			buf.clear();
			do {
				buf.push_back(code[i]);
				i++;
				if(code[i]==' '){
				code[i]='>';
				}
			} while (code[i - 1] != '>' && i < code.size());

			int j = 0;
			bool ex = false;

			while (j < SingleSIZE) {
				if (buf == singlemass[j]){
					ex = true; break;
				}
				j++;
			};
			j = 0;
			while (j < PairSIZE) {
				if (buf == PairedMass[j]) {
					ex = true;
					pairs[j]++;
					break;
				}
				if (buf == ClosedPairedMass[j]){
					ex = true;
					pairs[j]--;
					break;
				}
				j++;
			};
			if (!ex) {
				int h=0;
				for(h=0;h<incor.size();h++){
					if(incor[h].first==buf){
						incor[h].second++;
						break;
					}
				}
				if(h==incor.size())
						incor.push_back(make_pair(buf,1));
				fl = true;
			}
			for (j = 0; j <= PairSIZE; j++)
				if (pairs[j] == -1){
					pairs[j]++;
					fails[j]++;
					fl = true;
				}
		}else
		i++;
	}
	for (int l = 0; l < PairSIZE; l++){
		if (pairs[l] != 0){
			cout << "expected: " << ClosedPairedMass[l]<<" "<<pairs[l]<<" Times"<< endl;
			fl = true;
		}
		if(fails[l]!=0){
			cout  << PairedMass[l]<<" Undiscovered! "<<fails[l]<<" Times"<< endl;
			fl = true;
		}
	}
	for(int h=0;h<incor.size();h++){
		cout<<incor[h].first<<" Incorect! "<<incor[h].second<<" Tilmes"<< endl;			
	}
	if (!fl)
	cout << "Corect!";
	_gettch();
}
