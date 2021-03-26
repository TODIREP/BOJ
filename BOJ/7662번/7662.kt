import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
    fun getToken() = StringTokenizer(readLine()).nextToken()

    var testCase = getToken().toInt()

    repeat(testCase) {
        val k = getToken().toInt()
        val dataSet = TreeMap<Int, Int>()

        repeat(k) {
            val (oper, number) = readLine().split(" ").map{ it }
            val num = number.toInt()

            when (oper) {
                "I" -> {
                    dataSet[num] = dataSet.getOrDefault(num, 0) + 1
                }
                else -> {
                    if (dataSet.isNotEmpty()) {
                        val (key, value) = if (num == 1) {
                            dataSet.lastEntry()
                        } else {
                            dataSet.firstEntry()
                        }

                        if (value == 1) {
                            dataSet.remove(key)
                        } else {
                            dataSet[key] = value - 1
                        }
                    }
                }
            }
        }

        bufferedWriter.write("${if (dataSet.isEmpty()) {
            "EMPTY"
        } else {
            "${dataSet.lastKey()} ${dataSet.firstKey()}"
        }}\n")

        testCase--
    }
    bufferedWriter.close()
}

fun main() {
    solution()
}