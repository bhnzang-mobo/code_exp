class Person(name : String, age : Int){
    var __name : String = " "
    var __age : Int = 0
    init{
        __name=name
        __age=age
    }
    fun getName() : String {
        return this.__name
    }
    fun getAge() : Int{
        return this.__age
    }

}

fun getPeople(): List<Person> {
    return listOf(Person("Alice", 29), Person("Bob", 31))
}

fun comparePeople(): Boolean {
    val p1 = Person("Alice", 29)
    val p2 = Person("Alice", 29)
    return p1 == p2  // should be true
}