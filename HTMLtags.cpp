#include "stdafx.h" 
#include "HTMLtags.h" 

using namespace std;
using namespace tags;

string ClosedPairedMass[] = { "</a>","</abbr>","</address>","</acronym>","</applet>","</article>","</aside>"," </audio>",
"</b>","</bdi>","</bdo>","</big>","</blink>","</blockquote>","</body>","</button>","</canvas>","</caption>","</center>",
"</cite>","</code>","</colgroup>","</comment>","</datalist>","</dd>","</del>","</details>","</dfn>","</dialog>",
"</dir>" ,"</div>" ,"</dl>","</dt>","</em>","</fieldset>" ,"</figcaption>","</figure>","</font>","</footer>","</form>",
"</frame>","</frameset>","</h*>","</head>","</header>","</hgroup>","</html>","</i>","</iframe>","</ins>","</kbd>","</label>",
"</legend>","</li>","</listing>","</map>","</mark>","</marquee>","</menu>","</meter>","</multicol>","</nav>","</nobr>"
,"</noembed>","</noframes>","</noscript>","</object>","</ol>","</optgroup>","</option>","</output>","</p>","</plaintext>",
"</pre>","</progress>","</q>","</rp>","</rt>","</ruby>","</s>","</samp>","</script>","</section>","</select>","</small>",
"</spacer>","</span>","</strike>","</strong>","</style>","</sub>","</summary>","</sup>","</table>","</tbody>","</td>",
"</textarea>","</tfoot>","</th>","</thead>","</time>" ,"</title>","</tr>","</tt>","</u>","</ul>","</var>","</video>" ,"</xmp>" };
string PairedMass[] = { "<a>","<abbr>","<address>","<acronym>","<applet>","<article>","<aside>","<audio>","<b>",
"<bdi>","<bdo>","<big>","<blink>","<blockquote>","<body>","<button>","<canvas>","<caption>","<center>","<cite>",
"<code>","<colgroup>","<comment>","<datalist>","<dd>","<del>","<details>","<dfn>", "<dialog>","<dir>","<div>","<dl>",
"<dt>","<em>","<fieldset>","<figcaption>","<figure>","<font>","<footer>","<form>","<frame>","<frameset>","<h*>","<head>",
"<header>","<hgroup>","<html>","<i>","<iframe>","<ins>","<kbd>","<label>" ,"<legend>" ,"<li>" ,
"<listing>","<map>" ,"<mark>","<marquee>","<menu>","<meter>","<multicol>","<nav>","<nobr>","<noembed>","<noframes>"
,"<noscript>","<object>","<ol>","<optgroup>","<option>","<output>","<p>","<plaintext>","<pre>","<progress>","<q>" ,"<rp>",
"<rt>" ,"<ruby>" ,"<s>" ,"<samp>" ,"<script>" ,"<section>" ,"<select>" ,"<small>" ,"<spacer>" ,"<span>" ,"<strike>" ,
"<strong>" ,"<style>" ,"<sub>" ,"<summary>" ,"<sup>" ,"<table>" ,"<tbody>" ,"<td>" ,"<textarea>" ,"<tfoot>" ,"<th>" ,"<thead>" ,
"<time>" ,"<title>" ,"<tr>" ,"<tt>" ,"<u>" ,"<ul>" ,"<var>" ,"<video>" ,"<xmp>" };
string singleclosedmass[] = { "</area>", "</base>", "</basefont>", "</bgsound>", "</br>", "</col>", "</command>", "</embed>", "</hr>", "</img>", "</input>", "</isindex>", "</keygen>", "</link>", "</meta>", "</param>", "</source>", "</track>", "</wbr>" };
string singlemass[] = { "<area>","<base>","<basefont>","<bgsound>","<br>","<col>","<command>","<embed>","<hr>","<img>","<input>","<isindex>","<keygen>","<link>","<meta>","<param>","<source>","<track>","<wbr>" };
string code;

int pairedtags::is_close(int poz, int ind) {
		if(poz==-1){
		return -1;
		}
		string buf;
		bool ex = false;
		while (poz < code.size()) {
			if (code[poz] == '<') {
				buf.clear();
				do{
					buf.push_back(code[poz]);
					poz++;
				}while (code[poz-1] != '>' && poz < code.size());
					int j=0;
					while (j < 109 && buf != PairedMass[j]) {
						j++;
						if (j < 109 && buf == PairedMass[j]) {
							poz=is_close(poz, j);
							ex = true; break;
						}
					};
					j = 0;
					while (j < 19 && buf != singlemass[j]) {
						j++;
						if (j < 19 && buf == singlemass[j]) {
							ex = true; break;
						}
					};
					j = 0;
					while (j < 19 && buf != singleclosedmass[j]) {
						j++;
						if (j < 19 && buf == singleclosedmass[j]) {
							ex = true; break;
						}
					};
					if (buf == ClosedPairedMass[ind])
						return poz;
					if (!ex) {
						cout << buf << "Incorect!" << endl;
						system("Pause");
						return -1;
					}
			}
			poz++;
		}
		return -1;
	};



void tags::TagsTest(string adres)
{
	string buf;
	ifstream HTMLcode(adres);
	if(HTMLcode.is_open()){
	while (HTMLcode >> buf)
		code.append(buf);
	}
	else{
		cout<<"Incorect adres!"<<endl;
		system("Pause");
		return;
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
					nom = 1; ex = true;ind=j; break;
				} 
			};
			j = 0;
			while (j < 19 && buf != singleclosedmass[j]) {
				j++;
				if (j < 19 && buf == singleclosedmass[j]){
					nom = 2; ex = true;ind=j; break;
				}
			};
			j = 0;
			while (j < 109 && buf != PairedMass[j]) {
				j++; 
				if (j < 109 && buf == PairedMass[j]) {
					nom = 3; ex = true;ind=j; break;
				}
			};
			j = 0;
			while (j < 109 && buf != ClosedPairedMass[j]) {
				j++; 
				if (j < 109 && buf == ClosedPairedMass[j]){
					nom = 4; ex = true;ind=j;  break;
				}
			};
			if (!ex) {
				cout << buf << " Incorect!" << endl;
				system("Pause");
				return;
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
				cout<<buf<<" Unclosed!"<<endl;
				system("Pause");
				return;
				}
				break;
			case 4:
				cout << buf << " Incorect Closed tag!" << endl;
				system("Pause");
				return;
				break;
			default:
				break;
			}
		}
	}
	cout<<"Corect!";
}
