# Program ADT Combination tentang Game


## **Penggunaan Sll**
1. Pada `Accept New Quest`, saat menambahkan quest, quest akan otomatis paling akhir. menggunakan Insert last

2. pada `Complete a Quest`, akan melakukan operation deletion search,
   jadi user akan memasukkan id dari quest kemudian quest berdasarkan id tersebut akan terdelete

3. pada `View Active Quests`, akan menampilkan Quest dari aawal ke akhir


## **Penggunaaan Stack**
1. Ada di fitur `Undo Last Action` menerapkan sistem **_LIFO_ (Last In First Out)**, yang dimana setiap option (kecuali option tampilkan), akan melakukan push ke stack 
   sehingga saat option undo terpilih, akan melakukan Pop pada bagian atas stack

## **Penggunaan Queue**
1. Ada di fitur `Process Next Event`, menerapkan sistem **_FIFO_ (First In First Out)**, yang dimana, setiap selection pada option _Progress Events_ akan menyelesaikan
   event yang pertama terlebih dahulu



**Referensi:** 
> 1. [Pak Ade's Code](https://drive.google.com/file/d/1xAQHkF3mZfXNSP3P5tAHSSdu4DeIDEYF/view?usp=sharing).
> 2. Deepseek
