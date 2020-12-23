<h1 align="center">Syntax-Checker</h1>
<p align="center">A versatile syntax checker written in C++. Checks for issues with keywords and brackets.</p>
<center>
  <img src="https://user-images.githubusercontent.com/29171692/102989441-7875ca00-44ca-11eb-9b7d-ac5ad093e91e.png" alt="Syntax Checker Image Loading..." >
</center>

## Syntax Check
Its a Semester Project built to correctly parse the `code` file and seperate keywords and brackets and checks for any mistake in the Syntax. Its highly versatile as it also would correctly parse each word or bracket separatly even if all the code is written in a single line. If any of the below condition would be True, the compilter would throw an error: 

<ul>
  <li>If Imbalanced Brackets detected .e.g <code>[ [ {] } ]</code></li>
  <li>Code doesn't start with the keyword <code>begin</code></li>
  <li>Code doesn't end with the keyword <code>end</code></li>
  <li><code>end</code> occurs without a <code>begin</code></li>
  <li><code>endif</code> occurs without an <code>if</code></li>
  <li><code>endfor</code> occurs without an <code>for</code></li>
  <li><code>endwhile</code> occurs without an <code>while</code></li>
  <li><code>elseif</code> occurs without an <code>if</code></li>
  <li><code>else</code> occurs without an <code>if</code></li>
  <li><code>else</code> occurs two times</li>
  <li>If brackets are not opened correctly like <code>begin{ {if int a; }endif }end</code></li>
</ul>
