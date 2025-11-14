import { View, Text, TextInput, TouchableOpacity, StyleSheet } from 'react-native';

export default function LoginScreen({ navigation }){
    return(
        <View style={styles.container}>
            <Text style={styles.title}>Login</Text>
            <TextInput placeholder="Email" style={styles.input}/>
            <TextInput placeholder="Password" style={styles.input} secureTextEntry/>
            <TouchableOpacity style={styles.button} onPress={() => navigation.replace('MainMenu')}>
                <Text style={styles.buttonText}>Masuk</Text>
            </TouchableOpacity>
        </View>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        backgroundColor: '#fff',
    },
    title: {
        fontSize: 24,
        fontWeight: 'bold',
        marginmarginBottom: 20,
    },
    input: {
        borderWidth: 1,
        borderColor: '#ccc',
        borderRadius: 10,
        width: '80%',
        padding: 10,
        marginVertical: 8,
    },
    button: {
        backgroundColor: '#009966',
        padding: 12, 
        borderRadius: 10, 
        width: '80%',
        alignItems: 'center',
    },
    buttonText: {
        color: '#fff',
        fontWeight: 'bold'
    },
});