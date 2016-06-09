# STEP_GOOGLE_HW2
step hw2
行列積を求める
①
Matrix.c
Matrix.py 
Matrix.Java
行列積を普通に計算するプログラムです。JavaとCに比べて、pythonは100倍も遅くなります。

②
http://www.cc.u-tokyo.ac.jp/support/kosyu/X01/shiryou-1.pdf　を参照して、行列積の高速化を試みました。
C言語では行方向にデータをアクセスしたほうがキャッシュの再利用にはいいですから、行列を転置して行列積を計算しました。
matrix_c_transpose.cはそれに対応するコードです。
多少速くなりましたが、明らかに計算速度が速くなることが見られませんでした。
また、ブロック化も試してみましたが、計算時間は確かに減りました。おおよそ元の1/4になります。
matrix_try1.cはそれに対応するコードです。Openmpを使って、計算を並列化したら、さらに速くなると思います。
