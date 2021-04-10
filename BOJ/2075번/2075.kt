import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = readLine().toInt()
    val queue = PriorityQueue<Int>()
    repeat(n) {
        val current = readLine().split(" ").map(String::toInt)
        repeat(n) { index -> queue.add(current[index]) }
        while (queue.size > n) queue.remove()
    }
    bw.write("${queue.remove()}")
    bw.close()
}
fun main() {
    solution()
}