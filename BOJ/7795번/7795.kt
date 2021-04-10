import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    fun getInput() = readLine().split(" ").map(String::toInt)
    fun lowerBound(arr: IntArray, num: Int): Int {
        var left = 0
        var right = arr.size
        while (left < right) {
            val mid = (left + right) / 2
            if (arr[mid] >= num) right = mid
            else left = mid + 1
        }
        return left
    }
    val t = readLine().toInt()
    repeat(t) {
        var res = 0
        getInput()
        val a = getInput().toIntArray()
        val b = getInput().sorted().toIntArray()

        a.forEach { item ->
            res += lowerBound(b, item)
        }
        bw.write("$res\n")
        bw.flush()
    }
    bw.close()
}
fun main() {
    solution()
}