# Animasi(Timer)

Untuk membuat animasi kita butuh memanggil fungsi `glutMainFunc` yang menerima sebuah interval, callback, dan value.

Nilai dalam interval bisa di isi `1000 / SCREEN_FPS` untuk interval 1000 FPS.

Callback memerima prosedur berisi proses rendering seperti `glutPostRedisplay` untuk menggambar ulang tampilan.

Value merupakan nilai yang akan dimasukkan langsung dalam callback.

Fungsi `display` akan dipanggil lagi sesuai panjang interval. Di kasus ini `shapeMove` dipanggil berulang-ulang dengan posisi yang berubah sesuai iterasi.
<br/>
<br/>
## Daftar File
- [timerRotasiZ](./timerRotasiZ.cpp) (Membuat objek berputar pada sumbu Z)
- [timerRotasiY](./timerRotasiY.cpp) (Membuat objek berputar pada sumbu Y)
- [timerRotasiX](./timerRotasiX.cpp) (Membuat objek berputar pada sumbu X)
- [timerTranslasiX](./timerTranslasiX.cpp) (Membuat objek bergerak sepanjang sumbu X)
- [timerTranslasiY](./timerTranslasiY.cpp) (Membuat objek bergerak sepanjang sumbu Y)
- [timerTranslasiZ](./timerTranslasiZ.cpp) (Membuat objek bergerak sepanjang sumbu Z)
- [timerScale](./timerScale.cpp) (Membuat objek melebar/memanjang terhadap sumbu X dan Y)
- [balingBaling](./balingBaling.cpp) (Membuat dua objek baling-baling yang berputar secara berlawanan)




