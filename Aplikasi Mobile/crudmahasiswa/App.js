import { useEffect, useState } from "react";
import { Button, FlatList, StyleSheet, Text, TextInput, View } from "react-native";


const App = () => {
  const [listData, setListData] = useState([]);
  const [npm, setNPM] = useState("");
  const [nama, setNama] = useState("");
  const [programstudi, setProgramstudi] = useState("");
  const [isEdit, setIsEdit] = useState("");

  useEffect(() => {
    fetch("http://192.168.1.4/api_rn/api.php")
      .then((response) => response.json())
      .then((json) => {
        console.log("Hasil yang didapat: " + JSON.stringify(json.data.result));
        setListData(json.data.result);
      })
      .catch((error) => {
        console.log(error);
      });
  }, []);

  const simpan = async () => {
    if (!nama) {
      alert("Nama harus diisi");
      return;
    }
    if (!npm) {
      alert("NPM harus diisi");
      return;
    }
    if (!programstudi) {
      alert("Program Studi harus diisi");
      return;
    }
    fetch("http://192.168.1.4/api_rn/api.php?op=create", {
      method: "POST",
      headers: "nama=" + nama + "$npm=" + npm + "$program_studi=" + programstudi,
    })
      .then((response) => response.json())
      .then((json) => {
        console.log("Hasil yang didapat:" + json.data.result);
        alert("Data berhasil ditambahkan");
        setNama("");
        setNPM("");
        setProgramstudi("");
        setIsEdit("");
        fetch("http://192.168.1.4/api_rn/api.php")
          .then((response) => response.json())
          .then((json) => {
            console.log(
              "Hasil yang didapat: " + JSON.stringify(json.data.result)
            );
            setListData(json.data.result);
          });
      });
  };

  const update = async () => {
    fetch("http://192.168.1.4/api_rn/api.php?op=update&id=" + id, {
      method: "POSt",
      headers: "nama=" + nama + "$npm=" + npm + "$program_studi=" + programstudi,
    })
      .then((response) => response.json())
      .then((json) => {
        console.log("Hasil yang didapat: " + json.data.result);
        alert("Data berhasil diupdate");
        setNama("");
        setNPM("");
        setProgramstudi("");
        setIsEdit("");
        fetch("http://192.168.1.4/api_rn/api.php")
          .then((response) => response.json())
          .then((json) => {
            console.log(
              "Hasil yang didapat: " + JSON.stringify(json.data.result)
            );
            setListData(json.data.result);
          });
      });
  };

  const handle = async () => {
    if (!isEdit) {
      simpan();
    } else {
      update();
    }
  };

  const klikedit = async (id) => {
    fetch("http://192.168.1.4/api_rn/api.php?op=detail&id=" + id)
      .then((response) => response.json())
      .then((json) => {
        console.log("Hasil yang didapat: " + JSON.stringify(json.data.result));
        setNama(json.data.result[0].nama);
        setNPM(json.data.result[0].npm);
        setProgramstudi(json.data.result[0].program_studi);
        setId(json.data.result[0].id);
        setIsEdit(1);
      })
      .catch((error) => {
        console.log(error);
      })
  }

  const klikdelete = async (id) => {
    fetch("http://192.168.1.4/api_rn/api.php?op=delete&id=" + id)
      .then((response) => response.json())
      .then((json) => {
        console.log("Hasil yang didapat: " + json.data.result);
        alert("Data berhasil didelete");
        fetch("http://192.168.1.4/api_rn/api.php")
          .then((response) => response.json())
          .then((json) => {
            console.log(
              "Hasil yang didapat: " + JSON.stringify(json.data.result)
            );
            setListData(json.data.result);
          });
      });
  };

  return (
    <View style={style.viewWrapper}>
      <View style={style.viewData}>
        <FlatList
          data={listData}
          renderItem={({ item }) => (
            <View style={style.viewList}>
              <Text style={style.textListNama}>
                {item.nama}-{item.npm}
              </Text>
              <Text style={style.textListEdit} onPress={() => klikedit(item.id)}>
                Edit
              </Text>
              <Text style={style.textListDelete} onPress={() => klikdelete(item.id)}>
                Delete
              </Text>
            </View>
          )}
        />
      </View>
      <View style={style.viewForm}>
        <TextInput
        style={style.textInput}
        placeholder="Masukkan NPM"
        value={npm}
        onChangeText={(npm) => setNPM(npm)}
        ></TextInput>
        <TextInput
        style={style.textInput}
        placeholder="Masukkan Nama"
        value={nama}
        onChangeText={(nama) => setNama(nama)}
        ></TextInput>
        <TextInput
        style={style.textInput}
        placeholder="Masukkan Program Studi"
        value={programstudi}
        onChangeText={(programstudi) => setProgramstudi(programstudi)}
        ></TextInput>
        <Button title="Masukkan Data" onPress={() => handle()}></Button>
      </View>
    </View>
  )
}

const style = StyleSheet.create({
  viewWrapper: {
    flex: 1,
    marginTop: 30,
  },
  viewForm: {
    flex: 2,
    padding: 10,
  },
  viewData: {
    flex: 4,
  },
  textInput: {
    padding: 10,
    fontSize: 15,
    borderRadius: 15,
    borderWidth: 1,
    borderColor: '#CCC',
    marginBottom: 10,
    backgroundColor: '#dedede',
  },
  viewList: {
    flexDirection: 'row',
    padding: 5,
    borderBottomWidth: 1,
    borderBottomColor: '#dedede',
  },
  textListNama: {
    flex: 3,
    fontSize: 20,
    fontWeight: 'bold',
  },
  textListEdit: {
    color: 'blue',
    marginRight: 20,
  },
  textListDelete: {
    color: 'red',
  },
});

export default App;