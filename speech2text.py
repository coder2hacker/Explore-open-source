# Convert Speech to Text
#pip install SpeechRecognition
import speech_recognition as sr
def SpeechToText():
Ai = sr.Recognizer()
    with sr.Microphone() as source:
        listening = Ai.listen(source, phrase_time_limit = 6)  
    try:
        command = Ai.recognize_google(listening).lower()
        print("You said: " + command)
        
    except sr.UnknownValueError:
        print("Sorry Can't understand, Try again")
        SpeechToText()
