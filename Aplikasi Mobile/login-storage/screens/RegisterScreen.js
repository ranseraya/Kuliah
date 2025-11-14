import { useState } from 'react';
import { View, Text, TextInput, TouchableOpacity, StyleSheet, Alert } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';

export default function RegisterScreen({ navigation }) {

    const [name, setName] = useState("");
    const [email, setEmail] = useState("");
    const [password, setPassword] = useState("");

    const handleRegister = async () => {
        if (!name || !email || !password) {
            Alert.alert("Error", "Semua field wajib diisi");
            return;
        }

        const newUser = { name, email: email.toLowerCase(), password };

        try {
            const storedUsers = await AsyncStorage.getItem("users");
            let users = storedUsers ? JSON.parse(storedUsers) : [];

            const emailUsed = users.find(u => u.email === newUser.email);
            if (emailUsed) {
                Alert.alert("Error", "Email sudah terdaftar!");
                return;
            }

            users.push(newUser);
            await AsyncStorage.setItem("users", JSON.stringify(users));

            Alert.alert("Sukses", "Registrasi berhasil!");
            navigation.navigate("Login");

        } catch (e) {
            Alert.alert("Error", "Gagal menyimpan data.");
        }
    };
    return (
        <View style={styles.container}>
            <Text style={styles.title}>Register Akun</Text>

            <TextInput placeholder="Nama Lengkap" style={styles.input}
                value={name} onChangeText={setName}
            />

            <TextInput placeholder="Email" style={styles.input}
                value={email} onChangeText={setEmail}
            />

            <TextInput placeholder="Password" style={styles.input} secureTextEntry
                value={password} onChangeText={setPassword}
            />

            <TouchableOpacity style={styles.button} onPress={handleRegister}>
                <Text style={styles.buttonText}>Daftar</Text>
            </TouchableOpacity>

            <TouchableOpacity onPress={() => navigation.navigate('Login')}>
                <Text style={{ color: '#009966', marginTop: 10 }}>Sudah punya akun? Login</Text>
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