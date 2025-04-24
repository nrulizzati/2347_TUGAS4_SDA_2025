Nama	: Nurul Izzati
NPM	: 2308107010047

Tugas ini bertujuan untuk menguji dan membandingkan performa enam algoritma sorting—Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort, dan Shell Sort—dalam mengurutkan data angka dan kata dalam skala besar. Setiap algoritma diimplementasikan dalam fungsi tersendiri, dan program utama akan membaca data dari file (data_angka.txt dan data_kata.txt), kemudian mengukur waktu eksekusi serta penggunaan memori untuk masing-masing algoritma.

Hasil pengujian ditampilkan dalam bentuk tabel yang memuat informasi lama eksekusi dan jumlah memori yang digunakan. Program ditulis dalam bahasa C dan menggunakan API Windows (psapi.h) untuk profiling memori. Laporan tugas dilengkapi dengan deskripsi algoritma, tabel hasil eksperimen, grafik perbandingan, serta analisis dan kesimpulan dari pengujian.

Untuk menjalankan program, pengguna dapat meng-compile file tugas4.c menggunakan compiler GCC dengan perintah gcc tugas4.c -o tugas4 -lpsapi, yang menyertakan library psapi untuk mendukung pengukuran memori pada Windows. Setelah berhasil dikompilasi, jalankan program melalui terminal dengan ./tugas4, lalu masukkan jumlah data yang ingin diuji. Pastikan file data (data_angka.txt dan data_kata.txt) berada dalam direktori yang sama dengan file .exe agar program dapat berjalan dengan benar.