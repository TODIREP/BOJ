fun main() {
    readLine()!!.toInt()
    var res = 1
    val input = readLine()!!
    input.split(input[0]).forEach { if (it.isNotEmpty()) res++ }
    print("$res")
}