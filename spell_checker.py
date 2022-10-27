# Spell Checker in Python 
# pip install pyspellchecker
from spellchecker import SpellChecker as spell
Words = spell.unknown(['Python'  , 'is' , 'a' , 'good' , 'lantyguage'])
for w in Words:
    print(spell.correction(w)) #language
    print(spell.candidates(w)) #{ language }
