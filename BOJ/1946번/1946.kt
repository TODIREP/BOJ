import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val t = readLine().toInt()
    repeat(t) {
        val apply = mutableListOf<Pair<Int, Int>>()
        val n = readLine().toInt()

        repeat(n) {
            val (a, b) = readLine().split(" ").map(String::toInt)
            apply.add(Pair(a, b))
        }
        apply.sortBy { it.first }
        var prev = apply[0].second
        var cnt = 1
        for (index in 1 until n) {
            if (apply[index].second < prev) {
                prev = apply[index].second
                cnt++
            }
        }
        bw.write("$cnt\n")
    }
    bw.close()
}