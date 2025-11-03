import React, { useState } from "react";
import {
  View,
  Text,
  StatusBar,
  TouchableOpacity,
  StyleSheet,
  ImageBackground,
  FlatList,
  Alert,
  ToastAndroid,
  Linking,
  ScrollView,
} from "react-native";

const App = () => {
  const [header, setHeader] = useState("Home");

  const [switchv, setSwitchV] = useState(true);
  const [username, setUsername] = useState("");

  const [dataMahasiswa, setDataMahasiswa] = useState([
    { namaMhs: "Sarah", npmMhs: 13650027 },
    { namaMhs: "Dion", npmMhs: 13650097 },
    { namaMhs: "Virza", npmMhs: 13650077 },
    { namaMhs: "Dion", npmMhs: 13650197 },
    { namaMhs: "Virza", npmMhs: 13650277 },
  ]);

  return (
    <ScrollView style={styles.container}>
      <StatusBar barStyle="light-content" backgroundColor="#09bd75" />

      <View style={styles.imagecontainer}>
        <Text style={{ color: "#FFFFFF", fontWeight: "bold", fontSize: 25 }}>
          {header}
        </Text>
      </View>

      <TouchableOpacity
        style={styles.image}
        onPress={() =>
          Alert.alert("Information", "Anda akan menghapus gambar ini?", [
            {
              text: "Cancel",
              onPress: () => console.log("cancel ditekan"),
              style: "cancel",
            },
            { text: "Ok", onPress: () => console.log("ok ditekan") },
          ])
        }
      >
        <ImageBackground
          source={require("./assets/images/image1.jpg")}
          style={{
            width: 300,
            height: 300,
            justifyContent: 'flex-end',
            alignItems: 'center',
            padding: 20,
          }}
        >
          <Text style={{ color: 'white', fontSize: 15 }}>React-Native</Text>
        </ImageBackground>
      </TouchableOpacity>

      <TouchableOpacity
        style={styles.button}
        onPress={() => Linking.openURL('https://google.com/')}
      >
        <Text style={{ color: 'white' }}>Klik Google</Text>
      </TouchableOpacity>

      <FlatList
        style={{ flex: 1, paddingTop: 20 }}
        data={dataMahasiswa}
        renderItem={({ item }) => (
          <TouchableOpacity
            style={styles.flatlistitem}
            onPress={() =>
              ToastAndroid.show(item.namaMhs + ' diklik', ToastAndroid.SHORT)
            }
          >
            <Text style={{ color: 'white', fontSize: 20, fontWeight: 'bold' }}>
              {item.namaMhs}
            </Text>
            <Text style={{ color: 'white' }}>{item.npmMhs}</Text>
          </TouchableOpacity>
        )}
        keyExtractor={(item) => item.npmMhs.toString()}
      />
    </ScrollView>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  imagecontainer: {
    backgroundColor: "#03fc98",
    justifyContent: "center",
    alignItems: "center",
    elevation: 5,
    paddingVertical: 20,
  },
  image: {
    justifyContent: "center",
    alignItems: "center",
    marginTop: 20,
  },
  button: {
    backgroundColor: "#03fc98",
    paddingVertical: 20,
    justifyContent: "center",
    alignItems: "center",
    marginTop: 20,
    marginHorizontal: 20,
    borderRadius: 20,
    elevation: 3,
  },
  flatlistitem: {
    marginBottom: 20,
    backgroundColor: "#03fc98",
    marginHorizontal: 20,
    borderRadius: 5,
    paddingVertical: 10,
    paddingHorizontal: 20,
  },

  textinput: {
    borderWidth: 1,
    borderColor: "#03fc98",
    marginHorizontal: 20,
    paddingHorizontal: 10,
    borderRadius: 3,
    marginTop: 10,
    color: "black",
  },
  switch: {
    justifyContent: "center",
    alignItems: "center",
    marginTop: 20,
  },
});

export default App;