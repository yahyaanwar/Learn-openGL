# Animasi(Timer)

Untuk membuat animasi kita butuh memanggil fungsi `glutMainFunc` yang menerima sebuah interval, callback, dan value(opsional)

Nilai dalam interval bisa di isi `1000 / SCREEN_FPS` untuk interval 1000 FPS.

Callback memerima prosedur berisi proses rendering seperti `glutPostRedisplay` untuk menggambar ulang tampilan.

Value merupakan nilai yang akan dimasukkan langsung dalam callback.

Fungsi `display` akan dipanggil lagi sesuai panjang interval. Di kasus ini `shapeMove` dipanggil berulang-ulang dengan posisi yang berubah sesuai iterasi.

