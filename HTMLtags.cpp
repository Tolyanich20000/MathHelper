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





void pairedtags::TagsTest(string adres)
{
	int pairs[110] = { 0 };
	string buf;
	bool fl = false;
	ifstream HTMLcode(adres);
	if (HTMLcode.is_open()){
		while (HTMLcode >> buf)
			code.append(buf);
	}
	else{
		cout << "Incorect adres!" << endl;
		system("Pause");
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
			while (j < 109) {
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
			}
			for (j = 0; j <= 109; j++)
				if (pairs[j] == -1){
					cout << buf << " Undiscovered!" << endl;
					pairs[j]++;
				}
		}else
		i++;
	}
	for (int l = 0; l <= 109; l++)
		if (pairs[l] != 0){
			cout << "expected: " << ClosedPairedMass[l] << endl;
			fl = true;
		}
	if (!fl)
	cout << "Corect!";
	_gettch();
}
