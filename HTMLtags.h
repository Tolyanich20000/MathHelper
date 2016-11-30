#pragma once 
#include "stdafx.h"  

using namespace std;

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

class pairedtags {
public:
	pairedtags() {};
protected:
	static int is_close(int poz, int ind);
	friend void TagsTest(string adres);
};

