import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = readLine().toInt()
    val homework = mutableListOf<Pair<Int, Int>>()

    repeat(n) {
        val (date, score) = readLine().split(" ").map(String::toInt)
        homework.add(Pair(date, score))
    }
    homework.sortWith(compareByDescending { it.second })

    val res = IntArray(1001) { 0 }
    repeat(n) {
        for (index in homework[it].first downTo 1) {
            if (res[index] == 0) {
                res[index] = homework[it].second
                break
            }
        }
    }

    bw.write("${res.sum()}")
    bw.close()
}

fun main() {
    solution()
}