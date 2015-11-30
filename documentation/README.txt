% % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

This folder contains a groupwork report template for the
course ELEC-C5340 Applied digital signal processing. The
templates are based on the Acoustics seminar templates by
Aki Härmä and Vesa Välimäki.

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

Linux package requirements

For using this template you should only need the basic 
texlive packages:

texlive
texlive-latex-recommended
texlive-latex-extra

You can check whether you have a specific package 
installed with the dpkg command. For example, You can
check if you have texlive installed by typing

dpkg -s texlive

To install a package you can use the apt-get command. To 
install texlive type

sudo apt-get install texlive

Note: If you write in Finnish make sure you have the
package texlive-lang-finnish installed.

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

Compiling

To compile a .tex file to a .pdf with bibliography, enter
the following commands.

pdflatex raporttipohja.tex
bibtex raporttipohja.aux
pdflatex raporttipohja.tex
pdflatex raporttipohja.tex

Note that pdflatex is ran twice at
the end in purpose.

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

Todo:

The appearance of the Word and Latex templates are
different:

- The paragraph changes with a newline in Latex and indent 
in Word.

- The lines are hyphenated in Latex but not in Word.

- Headings are in capital letters in Word, not in Latex.

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

For more information contact Jussi Nieminen
(jussi.o.nieminen@aalto.fi) or the ELEC-C5340 course staff.

Modified: 11/2015
