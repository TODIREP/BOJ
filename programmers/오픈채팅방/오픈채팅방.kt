import java.util.*
class Solution {
    fun solution(record: Array<String>): Array<String> {
        val userName = TreeMap<String, String>()
        val temp = mutableListOf<String>()
        record.forEach {
            val item = it.split(" ")
            if (item[0] == "Enter" || item[0] == "Change") userName[item[1]] = item[2]
            if (item[0] == "Enter" || item[0] == "Leave") temp.add("${item[1]} ${item[0]}")
        }
        var answer = mutableListOf<String>()
        temp.forEach {
            val item = it.split(" ")
            answer.add("${userName[item[0]]}${
                       if (item[1] == "Enter") "님이 들어왔습니다."
                       else "님이 나갔습니다."
                       }")
        }
        return answer.toTypedArray()
    }
}