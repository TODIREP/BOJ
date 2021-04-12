import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val num = charArrayOf('0', '1', '2', '4', '6', '7', '8')
    val cnt = intArrayOf(6, 2, 5, 4, 6, 3, 7)
    val total: Array<String?> = arrayOfNulls(101)
    fun compare(a: String, b: String): Boolean {
        return when {
            (a.length == b.length) -> a.compareTo(b)
            else -> a.length - b.length
        } < 0
    }
    for (it in 1 until 7) {
        total[cnt[it]] = num[it].toString()
    }
    repeat(101) loop@ { cur ->
        if (total[cur] == null) return@loop
        repeat(7) { index ->
            val nxtCnt = cur + cnt[index]
            if (nxtCnt <= 100) {
                val nxtNum = total[cur].plus(num[index].toString())
                if (total[nxtCnt] == null) total[nxtCnt] = nxtNum
                else {
                    if (compare(nxtNum, total[nxtCnt]!!)) {
                        total[nxtCnt] = nxtNum
                    }
                }
            }
        }
    }
    val t = readLine().toInt()
    repeat(t) {
        var n = readLine().toInt()
        bw.write("${total[n]} ")
        if (n % 2 == 1) {
            bw.write("7")
            n -= 3
        }
        n /= 2
        repeat(n) {
            bw.write("1")
        }
        bw.write("\n")
    }
    bw.close()
}
fun main() {
    solution()
}