from tkinter import *
import tkinter.messagebox as mb
from path import Path
from PyPDF4.pdf import PdfFileReader as PDFreader, PdfFileWriter as PDFwriter
import pyttsx3
from speech_recognition import Recognizer, AudioFile
from pydub import AudioSegment
import os


# Initializing the GUI window
class Window(Tk):
    def __init__(self):
        super(Window, self).__init__()
        self.title("PDF to Audio and Audio to PDF converter")
        self.geometry('400x250')
        self.resizable(0, 0)
        self.config(bg='Black')

        Label(self, text='PDF to Audio and Audio to PDF converter',
              wraplength=400, bg='Black',
              font=("Comic Sans MS", 15)).place(x=0, y=0)

        Button(self, text="Convert PDF to Audio",
               font=("Comic Sans MS", 15), bg='cyan',
               command=self.pdf_to_audio, width=25).place(x=40, y=80)

        Button(self, text="Convert Audio to PDF",
               font=("Comic Sans MS", 15), bg='cyan',
               command=self.audio_to_pdf, width=25).place(x=40, y=150)

    def pdf_to_audio(self):
        pta = Toplevel(self)
        pta.title('Convert PDF to Audio')
        pta.geometry('500x300')
        pta.resizable(0, 0)
        pta.config(bg='cyan')
        Label(pta, text='Convert PDF to Audio', font=('Comic Sans MS', 15), bg='cyan').place(relx=0.3, y=0)
        Label(pta, text='Enter the PDF file location (with extension): ', bg='cyan', font=("Verdana", 11)).place(
            x=10, y=60)
        filename = Entry(pta, width=32, font=('Verdana', 11))
        filename.place(x=10, y=90)
        Label(pta, text='Enter the page to read from the PDF (only one can be read): ', bg='cyan',
              font=("Verdana", 11)).place(x=10, y=140)
        page = Entry(pta, width=15, font=('Verdana', 11))
        page.place(x=10, y=170)
        Button(pta, text='Speak the text', font=('Gill Sans MT', 12), bg='Snow', width=20,
               command=lambda: self.speak_text(filename.get(), page.get())).place(x=150, y=240)

    def audio_to_pdf(self):
        atp = Toplevel(self)
        atp.title('Convert Audio to PDF')
        atp.geometry('675x300')
        atp.resizable(0, 0)
        atp.config(bg='cyan')
        Label(atp, text='Convert Audio to PDF', font=("Comic Sans MS", 15), bg='cyan').place(relx=0.36, y=0)
        Label(atp, text='Enter the Audio File location that you want to read [in .wav or .mp3 extensions only]:',
              bg='cyan', font=('Verdana', 11)).place(x=20, y=60)
        audiofile = Entry(atp, width=58, font=('Verdana', 11))
        audiofile.place(x=20, y=90)
        Label(atp, text='Enter the PDF File location that you want to save the text in (with extension):',
              bg='cyan', font=('Verdana', 11)).place(x=20, y=140)
        pdffile = Entry(atp, width=58, font=('Verdana', 11))
        pdffile.place(x=20, y=170)
        Button(atp, text='Create PDF', bg='Snow', font=('Gill Sans MT', 12), width=20,
               command=lambda: self.speech_recognition(audiofile.get(), pdffile.get())).place(x=247, y=230)

    @staticmethod
    def speak_text(filename, page):
        if not filename or not page:
            mb.showerror('Missing field!', 'Please check your responses,'
                                           'because one of the fields is missing')
            return
        reader = PDFreader(filename)
        engine = pyttsx3.init()
        with Path(filename).open('rb'):
            page_to_read = reader.getPage(int(page) - 1)
            text = page_to_read.extractText()
            engine.say(text)
            engine.runAndWait()

    @staticmethod
    def write_text(filename, text):
        writer = PDFwriter()
        writer.addBlankPage(72, 72)
        pdf_path = Path(filename)
        with pdf_path.open('ab') as output_file:
            writer.write(output_file)
            output_file.write(text)

    def speech_recognition(self, audio, pdf):
        if not audio or not pdf:
            mb.showerror('Missing field!', 'Please check your responses, '
                                           'because one of the fields is missing')
            return
        audio_file_name = os.path.basename(audio).split('.')[0]
        audio_file_extension = os.path.basename(audio).split('.')[1]
        if audio_file_extension != 'wav' and audio_file_extension != 'mp3':
            mb.showerror('Error!', 'The format of the audio file should '
                                   'only be either "wav" and "mp3"!')
        if audio_file_extension == 'mp3':
            audio_file = AudioSegment.from_file(Path(audio), format='mp3')
            audio_file.export(f'{audio_file_name}.wav', format='wav')
        source_file = f'{audio_file_name}.wav'
        r = Recognizer()
        with AudioFile(source_file) as source:
            r.pause_threshold = 5
            speech = r.record(source)
            text = r.recognize_google(speech)
            self.write_text(pdf, text)


# Finalizing the GUI window
app = Window()
app.update()
app.mainloop()
