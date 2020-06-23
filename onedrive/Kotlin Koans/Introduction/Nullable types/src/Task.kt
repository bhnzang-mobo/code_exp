fun sendMessageToClient(
        client: Client?, message: String?, mailer: Mailer
) {
    mailer.sendMessage(client?.personalInfo.email.toString(),message.toString())
}

class Client(val personalInfo: PersonalInfo?)
class PersonalInfo(val email: String?)
interface Mailer {
    fun sendMessage(email: String, message: String)
}
