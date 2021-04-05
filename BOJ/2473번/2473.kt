import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.absoluteValue

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = readLine().toInt()
    val arr = readLine().split(" ").map(String::toLong).toLongArray().sorted()
    var sum: Long = 3000000001
    var ra: Long = 0
    var rb: Long = 0
    var rc: Long = 0

    repeat(n) { prev ->
        var left = prev + 1
        var right = n - 1
        while (left < right) {
            val mySum = arr[prev] + arr[left] + arr[right]
            if (mySum.absoluteValue < sum) {
                sum = mySum.absoluteValue
                ra = arr[prev]
                rb = arr[left]
                rc = arr[right]
            }
            if (mySum < 0) left++
            else right--
        }
    }
    bw.write("$ra $rb $rc")
    bw.close()
}
fun main() {
    solution()
}