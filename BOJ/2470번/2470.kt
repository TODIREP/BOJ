import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.absoluteValue

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = readLine().toInt()
    val water = readLine().split(" ").map(String::toInt).sorted()
    var (l, r) = 0 to n - 1
    var value = water[0] + water[n - 1]
    var (left, right) = 0 to n - 1

    while (l < r) {
        val sum = water[l] + water[r]
        if (sum.absoluteValue < value) {
            value = sum.absoluteValue
            left = l
            right = r
        }
        when {
            sum < 0 -> l++
            else -> r--
        }
    }
    bw.write("${water[left]} ${water[right]}")
    bw.close()
}
fun main() {
    solution()
}