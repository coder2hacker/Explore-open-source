let speech = new SpeechSynthesisUtterance();
speech.lang = "en";

let voices = [];
window.speechSynthesis.onvoiceschanged = () => {
  voices = window.speechSynthesis.getVoices();
  speech.voice = voices[0];
//   let voiceSelect = document.querySelector("#voices");
//   voices.forEach((voice, i) => (voiceSelect.options[i] = new Option(voice.name, i)));
  var elems = document.querySelectorAll('select');
  var instances = M.FormSelect.init(elems);
};

document.querySelector("#rate").addEventListener("input", () => {
    const rate = document.querySelector("#rate").value;
    speech.rate = rate;
    document.querySelector("#rate-label").innerHTML = rate;
  });

//   document.querySelector("#voices").addEventListener("change", () => {
//     speech.voice = voices[document.querySelector("#voices").value];
//   });


 
 // Path to PDF file
 var PDF_URL = './resume.pdf';
 const inputElement = document.getElementById("input");
 inputElement.addEventListener("change", handleFiles, false);

 function handleFiles() {
     const fileList = this.files; /* now you can work with the file list */
     console.log(fileList[0].name)
     PDF_URL=fileList[0].name
     _OBJECT_URL = URL.createObjectURL(fileList[0])
 }
 // Specify the path to the worker
 // pdfjsLib.workerSrc = './pdfjs/build/pdf.worker.js';

 // var loadingTask = pdfjsLib.getDocument('resume.pdf');
 // loadingTask.promise.then(function(pdf) {
 // console.log(pdf);
 // var pageNumber = 1;
 //     pdf.getPage(pageNumber).then(function(page) {
 //         page.getTextContent().then(text=>{
 //             text.items.forEach(element => {
 //                 console.log(element.str)

 //             });

 //         })
 //     })
 // })

 /**
  * Retrieves the text of a specif page within a PDF Document obtained through pdf.js 
  * 
  * @param {Integer} pageNum Specifies the number of the page 
  * @param {PDFDocument} PDFDocumentInstance The PDF document obtained 
  **/
 function getPageText(pageNum, PDFDocumentInstance) {
     // Return a Promise that is solved once the text of the page is retrieven
     return new Promise(function (resolve, reject) {
         PDFDocumentInstance.getPage(pageNum).then(function (pdfPage) {
             // The main trick to obtain the text of the PDF page, use the getTextContent method
             pdfPage.getTextContent().then(function (textContent) {
                 var textItems = textContent.items;
                 var finalString = "";

                 // Concatenate the string of the item to the final string
                 for (var i = 0; i < textItems.length; i++) {
                     var item = textItems[i];

                     finalString += item.str + " ";
                 }

                 // Solve promise with the text retrieven from the page
                 resolve(finalString);
             });
         });
     });
 }
 document.getElementById('speak').addEventListener('click', function () {

     var loadingTask = pdfjsLib.getDocument({url:_OBJECT_URL})
     loadingTask.promise.then(PDFDocumentInstance => {
         var totalPages = PDFDocumentInstance.numPages;
         document.getElementById('pageno').setAttribute('max',totalPages)
         var pageNumber =parseInt(document.getElementById('pageno').value);
         console.log( typeof(pageNumber) )

         // Extract the text
         getPageText(pageNumber, PDFDocumentInstance).then(function (textPage) {
             // Show the text of the page in the console
             
             speech.text = textPage.toLowerCase() ;
             window.speechSynthesis.speak(speech);
             console.log(textPage.toLowerCase());
         });
     })
 })

 document.querySelector("#cancel").addEventListener("click", () => {
     console.log("Stoped")
    window.speechSynthesis.cancel();
  });

  // document.querySelector("#pause").addEventListener("click", () => {
  //   window.speechSynthesis.pause();
  // });
  
  // document.querySelector("#resume").addEventListener("click", () => {
  //   window.speechSynthesis.resume();
  // });