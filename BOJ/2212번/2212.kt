import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
    fun inputList(size: Int): MutableList<Int> {
        val arr = mutableListOf<Int>()
        val token = StringTokenizer(readLine())
        for (i in 0 until size) {
            val number = token.nextToken().toInt()
            arr.add(number)
        }
        arr.sort()
        return arr
    }

    val n = readLine().toInt()
    val k = readLine().toInt()
    val sensor = inputList(n)

    val dis = mutableListOf<Int>()
    for (index in 1 until n) {
        dis.add(sensor[index] - sensor[index - 1])
    }
    dis.sort()

    var result: Long = 0
    for (index in 0 until n - k) {
        result += dis[index].toLong()
    }

    bufferedWriter.write("$result")
    bufferedWriter.close()
}
fun main() {
    solution()
}