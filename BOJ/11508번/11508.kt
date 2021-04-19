import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = readLine().toInt()
    val items = IntArray(n)
    repeat(n) {
        items[it] = readLine().toInt()
    }
    items.sortDescending()
    var result = 0
    repeat(n) {
        if ((it + 1) % 3 > 0) result += items[it]
    }
    bw.write("$result")
    bw.close()
}