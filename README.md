<h1 align="center">Syntax-Checker</h1>
<p align="center">A versatile syntax checker written in C++. Checks for issues with keywords and brackets.</p>
<center>
  <img src="https://user-images.githubusercontent.com/29171692/102989441-7875ca00-44ca-11eb-9b7d-ac5ad093e91e.png" alt="Syntax Checker Image Loading..." >
</center>

## Developers
<ul>
  <li><a href="//twitter.com/hash3liZer">Shameer Kashif</a></li>
  <li><a href="//www.facebook.com/siszaq2">Mahnam Nasir</a></li>
</ul>

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

## File Parsing
One the main algorithms built in this project is correctly parsing all the lines given in the file. The code is given below. The following code will accept a string meaning, a line and the line number and separate each word found and the brackets and pass it to another function named `validate`. All this code is available in the syntax.cpp file. 

```c++
void looper(string line, int line_counter) {
    string converter = "";
    for (int i = 0; i < line.length(); i++) {
        if (!isalpha(line[i]) || i + 1 == line.length()) {
           
           if (i + 1 == line.length()) {
               if (isalpha(line[i])) {
               converter += line[i];
               validate(converter, line_counter);
           }
           else {
               validate(converter, line_counter);
               converter = line[i];
               validate(converter, line_counter);
           }
        }
        else {
            validate(converter, line_counter);
            converter = line[i];
            validate(converter, line_counter);
        }
        converter = "";
      }
      else {
          converter += line[i];
      }
   }
}
```

## Compilation
The code was compiled and tested on **Visual Studio Community Version 2019**. However, it would perfectly compile on previous versions as well. Tested upto version `2012`. After compilation you can supply direct file as an argument. If you don't, the program will interactively ask to provide the file: 

<center>
  <img src="https://user-images.githubusercontent.com/29171692/102992479-1f109980-44d0-11eb-9a3f-477f81ce9bab.png" alt="Compiled File">
</center>

## Contribution
All code contribution are welcomed.
