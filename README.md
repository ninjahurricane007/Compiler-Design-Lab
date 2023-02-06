# How to run lex file
1. Save file with code in .l extension
2. Convert lex file to c file by executing 'lex filename.l'
3. Compile newly created lex.yy.c file by executing 'gcc lex.yy.c'
4. Execute './a.out'

# How to run yacc file
1. Save file with code in .y extension
2. Convert yacc file to c file by executing 'yacc -d filename.y'
3. Compile newly created y.tab.c file by executing 'gcc y.tab.c -ll'
4. Execute './a.out'

# How to run both lex and yacc files
1. Save file with lex code in .l and yacc code in .y extension
2. Convert yacc file to c file by executing 'yacc -d filename.y'
3. Convert lex file to c file by executing 'lex filename.l'
4. Compile both files by executing 'gcc lex.yy.c y.tab.c -ll'
5. Execute './a.out'
