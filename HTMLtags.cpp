#include "stdafx.h" 
#include "HTMLtags.h"

#define SIZE 120

using namespace std;
using namespace tags;

string ClosedPairedMass[] = { "</comment>","</DOCTYPE>","</a>","</abbr>", 
"</acronym>", 
"</address>", 
"</applet>" , 
"</area>", 
"</article>", 
"</aside>", 
"</audio>", 
"</b>", 
"</base>", 
"</basefont>", 
"</bdo>", 
"</big>", 
"</blockquote>", 
"</body>", 
"</br>", 
"</button>", 
"</canvas>", 
"</caption>", 
"</center>", 
"</cite>", 
"</code>", 
"</col>", 
"</colgroup>", 
"</command>", 
"</datagrid>", 
"</datalist>", 
"</datatemplate>", 
"</dd>", 
"</del>", 
"</details>", 
"</dialog>", 
"</dir>", 
"</div>", 
"</dfn>", 
"</dl>", 
"</dt>", 
"</em>", 
"</embed>", 
"</eventsource>", 
"</fieldset>", 
"</figure>", 
"</font>", 
"</footer>", 
"</form>", 
"</frame>", 
"</frameset>", 
"</h1>", "</h2>","</h3>","</h4>","</h5>", "</h6>", 
"</head>", 
"</header>", 
"</hr>", 
"</html>", 
"</i>", 
"</iframe>", 
"</img>", 
"</input>", 
"</ins>", 
"</isindex>", 
"</kbd>", 
"</label>", 
"</legend>", 
"</li>", 
"</link>", 
"</mark>", 
"</map>", 
"</menu>", 
"</meta>", 
"</meter>", 
"</nav>", 
"</nest>", 
"</noframes>", 
"</noscript>", 
"</object>" , 
"</ol>", 
"</optgroup>", 
"</option>", 
"</output>", 
"</p>", 
"</param>", 
"</pre>", 
"</progress>", 
"</q>", 
"</rule>", 
"</s>", 
"</samp>", 
"</script>", 
"</section>", 
"</select>", 
"</small>", 
"</source>", 
"</span>", 
"</strike>", 
"</strong>", 
"</style>", 
"</sub>", 
"</sup>", 
"</table>", 
"</tbody>", 
"</td>", 
"</textarea>", 
"</tfoot>", 
"</th>", 
"</thead>", 
"</time>", 
"</title>", 
"</tr>", 
"</tt>", 
"</u>", 
"</ul>", 
"</var>", 
"</video>", 
"</xmp>" };
string PairedMass[] = { "<comment>","<DOCTYPE>","<a>","<abbr>", 
"<acronym>", 
"<address>", 
"<applet>" , 
"<area>", 
"<article>", 
"<aside>", 
"<audio>", 
"<b>", 
"<base>", 
"<basefont>", 
"<bdo>", 
"<big>", 
"<blockquote>", 
"<body>", 
"<br>", 
"<button>", 
"<canvas>", 
"<caption>", 
"<center>", 
"<cite>", 
"<code>", 
"<col>", 
"<colgroup>", 
"<command>", 
"<datagrid>", 
"<datalist>", 
"<datatemplate>", 
"<dd>", 
"<del>", 
"<details>", 
"<dialog>", 
"<dir>", 
"<div>", 
"<dfn>", 
"<dl>", 
"<dt>", 
"<em>", 
"<embed>", 
"<eventsource>", 
"<fieldset>", 
"<figure>", 
"<font>", 
"<footer>", 
"<form>", 
"<frame>", 
"<frameset>", 
"<h1>", "<h2>","<h3>","<h4>","<h5>", "<h6>", 
"<head>", 
"<header>", 
"<hr>", 
"<html>", 
"<i>", 
"<iframe>", 
"<img>", 
"<input>", 
"<ins>", 
"<isindex>", 
"<kbd>", 
"<label>", 
"<legend>", 
"<li>", 
"<link>", 
"<mark>", 
"<map>", 
"<menu>", 
"<meta>", 
"<meter>", 
"<nav>", 
"<nest>", 
"<noframes>", 
"<noscript>", 
"<object>" , 
"<ol>", 
"<optgroup>", 
"<option>", 
"<output>", 
"<p>", 
"<param>", 
"<pre>", 
"<progress>", 
"<q>", 
"<rule>", 
"<s>", 
"<samp>", 
"<script>", 
"<section>", 
"<select>", 
"<small>", 
"<source>", 
"<span>", 
"<strike>", 
"<strong>", 
"<style>", 
"<sub>", 
"<sup>", 
"<table>", 
"<tbody>", 
"<td>", 
"<textarea>", 
"<tfoot>", 
"<th>", 
"<thead>", 
"<time>", 
"<title>", 
"<tr>", 
"<tt>", 
"<u>", 
"<ul>", 
"<var>", 
"<video>", 
"<xmp>" };
string singleclosedmass[] = { "</area>", "</base>", "</basefont>", "</bgsound>", "</br>", "</col>", "</command>", "</embed>", "</hr>", "</img>", "</input>", "</isindex>", "</keygen>", "</link>", "</meta>", "</param>", "</source>", "</track>", "</wbr>" };
string singlemass[] = { "<area>","<base>","<basefont>","<bgsound>","<br>","<col>","<command>","<embed>","<hr>","<img>","<input>","<isindex>","<keygen>","<link>","<meta>","<param>","<source>","<track>","<wbr>" };
string code;





void pairedtags::TagsTest(string adres)
{
	int pairs[SIZE] = { 0 };
	string buf;
	bool fl = false;
	ifstream HTMLcode;
	HTMLcode.open(adres);
	if (HTMLcode.is_open()){
		code.clear();
		while (HTMLcode >> buf)
			code.append(buf);
	}
	else{
		cout << "Incorect adres!" << endl;
		_gettch();
		return;
	}
	HTMLcode.close();
	//*********************************************
	int i = 0;
	while (i < code.size()) {

		if (code[i] == '<') {
			buf.clear();
			do {
				buf.push_back(code[i]);
				i++;
			} while (code[i - 1] != '>' && i < code.size());

			int j = 0;
			bool ex = false;

			while (j < 19) {
				if (buf == singlemass[j] && buf == singleclosedmass[j]){
					ex = true; break;
				}
				j++;
			};
			j = 0;
			while (j < SIZE) {
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
				cout << buf << " Incorect!" << endl;
				fl = true;
			}
			for (j = 0; j <= SIZE; j++)
				if (pairs[j] == -1){
					cout << buf << " Undiscovered!" << endl;
					pairs[j]++;
					fl = true;
				}
		}else
		i++;
	}
	for (int l = 0; l < SIZE; l++)
		if (pairs[l] != 0){
			cout << "expected: " << ClosedPairedMass[l] << endl;
			fl = true;
		}
	if (!fl)
	cout << "Corect!";
	_gettch();
}
