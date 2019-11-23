const char MAIN_page[] PROGMEM = R"=====(
<html>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
  <title>Ducks-to-db</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">



<style type="text/css">

#portal {
   display: block;
   min-height: 100vh;
   background: rgb(0,31,42);
   background: linear-gradient(207deg, rgba(0,31,42,1) 0%, rgba(255,117,79,1) 50%, rgba(251,78,30,1) 100%);
}

#portal .c {
   display: block;
   padding: 0 1.5em;
}

h1, h2, h3, h4, h5, p, span, a, .b, .gps {
  font-family: "Arial", sans-serif;
}

.head {
   padding: 15px 0;
   display: block;
   color: #fff;
   text-align: center;
}

.head h3 {
   font-weight: 700;
   margin: 1em 0 0;
   font-size: 1.35em;
}

.logo {

}

.logo img {
   display: block;
   height: 3em;
   margin: 1em auto;
}

.head.form {
   background: #0e2338;
}

.head.form .logo {
   display: inline-block;
}

.head.form .logo img {
   display: inline-block;
   height: 1.5em;
   margin: 0;
   vertical-align: top;
}

.head.form h3 {
   font-size: 1.15em;
   margin: 0 0 0 .5em;
   display: inline-block;
   vertical-align: top;
   line-height: 1.5em;
}

.body {
   padding: 1.5em 0;
   display: block;
}

.body.on {
   display: block;
}

.body.off {
   display: none;
}

.body p {
   color: #fff;
   margin: 0 0 1em;
}

.body h4 {
   font-size: 1.25em;
   color: #fff;
   font-weight: 600;
   margin: 1em 0 .5em;
}

.body.form {
   padding: 0;
   background: #e2e2e2;
}

.b {
   display: block;
   padding: 20px;
   text-align: center;
   cursor: pointer;
}

.b:hover {
   opacity: .7;
}

.lang, .details, .update, .home {
   display: block;
   color: #fff;
   border: 1px solid #fff;
   font-size: 1.25em;
   font-weight: 600;
   line-height: 1.5em;
   margin-bottom: 1em;
}

.details {
   background: #000000;
   border: 0;
}

.update {
   border: 0;
   background: #fe5454;
}

.body p.disclaimer {
   font-size: .9em;
   text-align: center;
}

.sos {
   font-size: 2em;
   color: #fff;
   letter-spacing: 3px;
   background: #000000;
   font-weight: 600;
}

.ch-c {
   margin-bottom: 1em;

}

.ch-c p {
   font-size: 1.25em;
   line-height: 2.15em;
   margin: 0;
   display: inline-block;
   vertical-align: top;
}

.ch-c input[type=checkbox] {
   display: inline-block;
   width: 2em;
   height: 2em;
   vertical-align: top;
   margin-left: 0;
}

.gps {
   display: block;
   padding: 1em;
   background: rgba(255,255,255,.75);
   text-align: center;
   font-size: 1.25em;
   line-height: 1.5em;
   letter-spacing: 1px;
}

.gps h4 {
   color: #111;
   font-size: 1.35em;
}

.gps h5 {
   color: #111;
   font-size: 1.15em;
}

.gps p {
   color: #111;
   font-size: 1em;
   letter-spacing: 2px;
}

#portal .body.form .c {
}

#portal .body.form .c .s {
   padding: 1em 0;
   border-bottom: 1px solid rgba(0,0,0,.15);
}

#portal .body.form .c .s:after {
   content: "";
   display: block;
   clear: both;
}

#portal .body.form .c .s:last-child {
   border: 0;
}

.body.form .gps {
   text-align: left;
   background: #fff;
}

.body.form .ch-c {
   display: inline-block;
   width: 48%;
}

.body.form .ch-c input[type=checkbox] {
   background: #fff;
}

.body.form .ch-c:nth-child(even) {
   width: 43%;
}

.body.form .ch-c:nth-child(odd) {
   width: 55%;
}

.body.form .ch-c p {
   color: #111;
   margin-left: .35em;
}

.body.form h4 {
   color: #111;
   display: inline-block;
   vertical-align: top;
   margin: 0 0 .25em;
   line-height: 1.5em;
}

.body.form input.other-input {
   display: block;
   width: 100%;
   margin-bottom: 1em;
   padding: 1em .5em;
   font-size: 16px;
}

.body.form input.num-input {
   display: inline-block;
   vertical-align: top;
   width: 20%;
   margin-bottom: 1em;
   padding: 1em .5em;
   float: right;
   font-size: 16px;
}

.body.form input.name-input, .body.form input.phone-input, .body.form input.address-input {
   display: block;
   width: 100%;
   margin-bottom: 1.5em;
   padding: 1em .5em;
   font-size: 16px;
}

.body.form textarea.message-input {
   display: block;
   width: 100%;
   min-height: 5em;
   vertical-align: top;
   margin-bottom: 1em;
   padding: 1em .5em;
   font-size: 16px;
}

.body .change {
   color: #fff;
   font-size: 1.15em;
   line-height: 1.5em;
}

.body .optional {
   background: #4ec1b5;
   font-size: 1em;
   line-height: 1.5em;
   padding: 1em 0;
   color: #fff;
   text-align: center;
   font-weight: 600;
}

</style>

<div id="portal">
   <div id="headEl" class="head">
      <div class="c">
         <div class="logo"><img src='data:image/png;base64,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' alt=''></div>
         <h3>OWL Emergency Network</h3>
      </div>
   </div>

   <div id="bodyIntro" class="body on intro">
      <div class="c">
         <div id="enesp" class="b lang">En Español</div>
         <p>You are connected to the OWL emergency network. Sending an SOS message will send your GPS location to First Responders and Emergency Management. You can send a quick SOS or add details about your emergency.</p>
         <p><b>The closest facilties to you are located at:</b><br>Willowbrook Shopping Centre</p>
         <br>
         <h4>Your GPS Location</h4>
         <div class="gps"><b>49.108192,-122.6995447</b><br>Surrey, BC, Canada</div>
         <div id="bisos" class="b sos">SOS</div>
      </div>
   </div>

   <div id="bodyIntroEs" class="body off intro">
      <div class="c">
         <div id="ening" class="b lang">En Ingles</div>
         <p>Se ha conectao a la Red de Emergencia OWL. Al enviar una solicitud de ayuda, estaremos enviando las coordenadas GPS de su localización a los Primeros Respondedores y Manejo de Emergencias. Puede enviar una solicitud de ayuda rápida o añadir detalles relacionados a su emergencia. Los campos son opcionales.</p>
         <p><b>El lugar de ayuda más cercana a usted está en:</b><br>Willowbrook Shopping Centre</p>
         <br>
         <h4>Su localización GPS</h4>
         <div class="gps"><b>49.108192,-122.6995447</b><br>Surrey, BC, Canada</div>
         <div id="bisosEs" class="b sos">AYUDA</div>
      </div>
   </div>

   <div id="bodySend" class="body off send">
      <div class="c">
         <div id="enespb" class="b lang">En Español</div>
         <br><br>
         <h4>Your GPS Location</h4>
         <div class="gps"><b>49.108192,-122.6995447</b><br>Surrey, BC, Canada</div>
         <div id="bssos" class="b sos">SEND SOS</div>
         <br><br><br>
         <div id="dmore" class="b details more">Add Details Before Sending</div>
      </div>
   </div>

   <div id="bodySendEs" class="body off send">
      <div class="c">
         <div id="eningb" class="b lang">En Ingles</div>
         <br><br>
         <h4>Su localizacion GPS</h4>
         <div class="gps"><b>49.108192,-122.6995447</b><br>Surrey, BC, Canada</div>
         <div id="bssosEs" class="b sos">AYUDA</div>
         <br><br><br>
         <div id="dmoreEs" class="b details more">Añadir Eetalles Antes de Enviar</div>
      </div>
   </div>

   <div id="bodySent" class="body off sent">
      <div class="c">
         <div id="bhome" class="b home">Home</div>
         <div class="gps"><h4>Message Sent</h4><h5 id="dateNow">March 13, 2019 @ 1:02 PM</h5><p>Your message ID#: 9XP002</p></div>
         <br><br><br><br>
         <p class="disclaimer">If your situation changes, please send another update.
         <div id="bupdate" class="b update">Send Update</div>
         <div class="change" style="width: 90%; display: inline-block;float: left;"><b>Change my status</b><br>I no longer need help</div>
         <input type="checkbox" style="width: 30px; height: 30px; display: inline-block;float: left;">
      </div>
   </div>

   <div id="bodySentEs" class="body off sent">
      <div class="c">
         <div id="bhomeEs" class="b home">Inicio</div>
         <div class="gps"><h4>Mensaje Enviado</h4><h5 id="dateNowEs">13 de marzo de 2019 @ 1:02 PM</h5><p># de ID de su mensaje: 9XP002</p></div>
         <br><br><br><br>
         <p class="disclaimer">Si su situación cambió, por favor envíe una actualización.
         <div id="bupdateEs" class="b update">ACTUALIZAR</div>
         <div class="change" style="width: 90%; display: inline-block;float: left;"><b>Actualizar mi condición</b><br>Ya no necesito ayuda</div>
         <input type="checkbox" style="width: 30px; height: 30px; display: inline-block;float: left;">
      </div>
   </div>

   <div id="bodyForm" class="body off form">
      <div class="optional">All Fields Are Optional</div>
      <div class="gps"><b>Your GPS Location</b><br>49.108192,-122.6995447</div>
      <div class="c">
         <div class="s">
            <h4>Phone Number</h4>
            <input type="text" placeholder="123-456-7891" class="phone-input" id="phoneInput">
            <h4>First Name / Last Name</h4>
            <input type="text" placeholder="Jess Smith" class="name-input" id="nameInput">
            <h4>Where are you?</h4>
            <input type="text" placeholder="Closest address, intersection, description" class="address-input" id="locationInput">
         </div>
         <div class="s">
            <h4>What is your emergency?</h4>
            <div class="ch-c"><input type="checkbox"><p>Medical</p></div>
            <div class="ch-c"><input type="checkbox"><p>Fire/Explosion</p></div>
            <div class="ch-c"><input type="checkbox"><p>Flood</p></div>
            <div class="ch-c"><input type="checkbox"><p>Violence</p></div>
            <div class="ch-c"><input type="checkbox"><p>Landslide</p></div>
            <div class="ch-c"><input type="checkbox"><p>Building Collapse</p></div>
            <div class="ch-c"><input type="checkbox"><p>Trapped</p></div>
            <div class="ch-c"><input type="checkbox"><p>Death</p></div>
            <input type="text" placeholder="Other emergency" class="other-input">
         </div>
         <div class="s">
            <h4>What do you need in the next 24 hours?</h4>
            <div class="ch-c"><input type="checkbox"><p>First Aid</p></div>
            <div class="ch-c"><input type="checkbox"><p>Shelter</p></div>
            <div class="ch-c"><input type="checkbox"><p>Food</p></div>
            <div class="ch-c"><input type="checkbox"><p>Financial Aid</p></div>
            <div class="ch-c"><input type="checkbox"><p>Water</p></div>
            <div class="ch-c"><input type="checkbox"><p>Evacuation</p></div>
            <div class="ch-c"><input type="checkbox"><p>Clothing</p></div>
            <div class="ch-c"><input type="checkbox"><p>Hygiene</p></div>
            <input type="text" placeholder="Other" class="other-input">
         </div>
         <div class="s">
            <h4>What hazards are directly around you?</h4>
            <div class="ch-c"><input type="checkbox"><p>Electrical</p></div>
            <div class="ch-c"><input type="checkbox"><p>Road Blocked</p></div>
            <div class="ch-c"><input type="checkbox"><p>Fallen Trees</p></div>
            <div class="ch-c"><input type="checkbox"><p>Chemical</p></div>
            <div class="ch-c"><input type="checkbox"><p>Smoke/Fire</p></div>
            <div class="ch-c"><input type="checkbox"><p>Animals</p></div>
            <div class="ch-c"><input type="checkbox"><p>Fast Current</p></div>
            <div class="ch-c"><input type="checkbox"><p>Explosives</p></div>
            <input type="text" placeholder="Other" class="other-input">
         </div>
         <div class="s">
            <h4>How many people?</h4>
            <input type="text" placeholder="0" class="num-input">
         </div>
         <div class="s">
            <h4>How many pets?</h4>
            <input type="text" placeholder="0" class="num-input">
         </div>
         <div class="s">
            <h4 style="width: 90%; float: left; display: inline-block;">Are you or anyone in your group immobile?</h4>
            <input type="checkbox" style="width: 30px; height: 30px; display: inline-block;float: left;">
         </div>
         <div class="s">
            <h4 style="width: 90%; float: left; display: inline-block;">Make your name public so friends/family know you are ok?</h4>
            <input type="checkbox" style="width: 30px; height: 30px; display: inline-block;float: left;">
         </div>
         <div class="s">
            <h4>Message (300 characters)</h4>
            <textarea type="text" placeholder="More information about your situation" class="message-input" id="messageInput"></textarea>
         </div>
         <div class="s">
            <!-- <h4>Change my status:<br>I no longer need help</h4> -->
            <div id="bfsos" class="b sos">SEND SOS</div>
         </div>
      </div>
   </div>

    <div id="bodyFormEs" class="body off form">
      <div class="optional">Todos los campos son opcionales</div>
      <div class="gps"><b>Su localización GPS</b><br>49.108192,-122.6995447</div>
      <div class="c">
         <div class="s">
            <h4>Teléfono</h4>
            <input type="text" placeholder="123-456-7891" class="phone-input" id="phoneInputEs">
            <h4>Nombre y Apellido</h4>
            <input type="text" placeholder="Jess Smith" class="name-input" id="nameInputEs">
            <h4>¿Dónde se encuentra?</h4>
            <input type="text" placeholder="Closest address, intersection, description" class="address-input" id="locationInputEs">
         </div>
         <div class="s">
            <h4>¿Cuál es su emergencia?</h4>
            <div class="ch-c"><input type="checkbox"><p>Medica</p></div>
            <div class="ch-c"><input type="checkbox"><p>Fuego / Explosión</p></div>
            <div class="ch-c"><input type="checkbox"><p>Inundación</p></div>
            <div class="ch-c"><input type="checkbox"><p>Violencia</p></div>
            <div class="ch-c"><input type="checkbox"><p>Derrumbe</p></div>
            <div class="ch-c"><input type="checkbox"><p>Estructura Colapsada</p></div>
            <div class="ch-c"><input type="checkbox"><p>Atrapado</p></div>
            <div class="ch-c"><input type="checkbox"><p>Muerte</p></div>
            <input type="text" placeholder="Other emergency" class="other-input">
         </div>
         <div class="s">
            <h4>¿Qué necesita en las próximas 24 hrs?</h4>
            <div class="ch-c"><input type="checkbox"><p>Primeros Aux</p></div>
            <div class="ch-c"><input type="checkbox"><p>Refugio</p></div>
            <div class="ch-c"><input type="checkbox"><p>Alimentos</p></div>
            <div class="ch-c"><input type="checkbox"><p>Ayuda Financiera</p></div>
            <div class="ch-c"><input type="checkbox"><p>Comida</p></div>
            <div class="ch-c"><input type="checkbox"><p>Evacuación</p></div>
            <div class="ch-c"><input type="checkbox"><p>Ropa</p></div>
            <div class="ch-c"><input type="checkbox"><p>Productos de Higiene</p></div>
            <input type="text" placeholder="Other" class="other-input">
         </div>
         <div class="s">
            <h4>¿Qué peligros hay a su alrededor?</h4>
            <div class="ch-c"><input type="checkbox"><p>Eléctricas Arbol</p></div>
            <div class="ch-c"><input type="checkbox"><p>Carretera Cerrada</p></div>
            <div class="ch-c"><input type="checkbox"><p>Caido</p></div>
            <div class="ch-c"><input type="checkbox"><p>Quimicos</p></div>
            <div class="ch-c"><input type="checkbox"><p>Huma/Fuego</p></div>
            <div class="ch-c"><input type="checkbox"><p>Animales</p></div>
            <div class="ch-c"><input type="checkbox"><p>Golpe de Agua</p></div>
            <div class="ch-c"><input type="checkbox"><p>Explosivos</p></div>
            <input type="text" placeholder="Other" class="other-input">
         </div>
         <div class="s">
            <h4>¿Cuántas personas?</h4>
            <input type="text" placeholder="0" class="num-input">
         </div>
         <div class="s">
            <h4>¿Cuántas mascotas?</h4>
            <input type="text" placeholder="0" class="num-input">
         </div>
         <div class="s">
            <h4 style="width: 90%; float: left; display: inline-block;">¿Usted o a alguien en su grupo se le hace imposible moverse?</h4>
            <input type="checkbox" style="width: 30px; height: 30px; display: inline-block;float: left;">
         </div>
         <div class="s">
            <h4 style="width: 90%; float: left; display: inline-block;">¿Autoriza a que su información se haga publica para que sus familiares o amigos sepan que se encuentra bien??</h4>
            <input type="checkbox" style="width: 30px; height: 30px; display: inline-block;float: left;">
         </div>
         <div class="s">
            <h4>Mensaje (300 caracteres)</h4>
            <textarea type="text" placeholder="More information about your situation" class="message-input" id="messageInputEs"></textarea>
         </div>
         <div class="s">
            <!-- <h4>Change my status:<br>I no longer need help</h4> -->
            <div id="bfsosEs" class="b sos">PEDIR AYUDA</div>
         </div>
      </div>
   </div>
</div>


<script type="text/javascript">

   var bodyIntro = document.getElementById("bodyIntro")
   var bodySend = document.getElementById("bodySend")
   var bodySendEs = document.getElementById("bodySendEs")
   var bodySent = document.getElementById("bodySent")
   var bodySentEs = document.getElementById("bodySentEs")
   var bodyForm = document.getElementById("bodyForm")
   var bodyFormEs = document.getElementById("bodyFormEs")
   var bisos = document.getElementById("bisos");
   var bisosEs = document.getElementById("bisosEs");
   var bssos = document.getElementById("bssos");
   var bssosEs = document.getElementById("bssosEs");
   var bfsos = document.getElementById("bfsos");
   var bfsosEs = document.getElementById("bfsosEs");
   var bhome = document.getElementById("bhome");
   var bhome = document.getElementById("bhomeEs");
   var besp = document.getElementById("enesp");
   var bing = document.getElementById("ening");
   var bespb = document.getElementById("enespb");
   var bingb = document.getElementById("eningb");
   var bupdate = document.getElementById("bupdate");
   var bupdateEs = document.getElementById("bupdateEs");
   var dmore = document.getElementById("dmore");
   var dmoreEs = document.getElementById("dmoreEs");
   var headEl = document.getElementById("headEl");

   bisos.addEventListener("click",function(e){
      bodySend.className += " on";
      bodySend.classList.remove('off');
      bodyIntro.classList.remove("on")
      bodyIntro.className += " off"
   },false);

   bisosEs.addEventListener("click",function(e){
      bodySendEs.className += " on";
      bodySendEs.classList.remove('off');
      bodyIntroEs.classList.remove("on")
      bodyIntroEs.className += " off"
   },false);

   besp.addEventListener("click",function(e){
      bodyIntroEs.className += " on";
      bodyIntroEs.classList.remove('off');
      bodyIntro.classList.remove("on")
      bodyIntro.className += " off"
   },false);

   bing.addEventListener("click",function(e){
      bodyIntro.className += " on";
      bodyIntro.classList.remove('off');
      bodyIntroEs.classList.remove("on")
      bodyIntroEs.className += " off"
   },false);

   bespb.addEventListener("click",function(e){
      bodyIntroEs.className += " on";
      bodyIntroEs.classList.remove('off');
      bodySend.classList.remove("on")
      bodySend.className += " off"
   },false);

   bingb.addEventListener("click",function(e){
      bodyIntro.className += " on";
      bodyIntro.classList.remove('off');
      bodySendEs.classList.remove("on")
      bodySendEs.className += " off"
   },false);

   dmore.addEventListener("click",function(e){
      headEl.className += " form"
      bodyForm.className += " on";
      bodyForm.classList.remove('off');
      bodySend.classList.remove("on")
      bodySend.className += " off"
   },false);

   dmoreEs.addEventListener("click",function(e){
      headEl.className += " form"
      bodyFormEs.className += " on";
      bodyFormEs.classList.remove('off');
      bodySendEs.classList.remove("on")
      bodySendEs.className += " off"
   },false);

   bssos.addEventListener("click",function(e){

      var d = new Date();
      document.getElementById("dateNow").innerHTML = "March " + d.getDate() + ", " + d.getFullYear() + " @ " + d.getHours() + ":" + d.getMinutes();

      var mid = "";
      var possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
      for (var i = 0; i < 4; i++) {
         mid += possible.charAt(Math.floor(Math.random() * possible.length));
      }

      var submitUrl = "?mid=" + mid + "&name=" + "Jess Smith" + "&location=" + "Isabela" + "&number=" + "1234567890" + "&occupants=" + "2" + "&danger=" + "1" + "&vacant=" + "0" + "&firstaid=" + "1" + "&water=" + "1" + "&food=" + "0" + "&msg=" + "Help me please!"
      console.log(submitUrl)

      bodySent.className += " on";
      bodySent.classList.remove('off');
      bodySend.classList.remove("on")
      bodySend.className += " off"

      var url = window.location.href;
      if (url.indexOf('?') > -1){
         url = url.split("?")[0]
         url += submitUrl
      }else{
         url += submitUrl
      }
      window.location.href = url;
   },false);

   bssosEs.addEventListener("click",function(e){

      var d = new Date();
      document.getElementById("dateNowEs").innerHTML = "March " + d.getDate() + ", " + d.getFullYear() + " @ " + d.getHours() + ":" + d.getMinutes();

      var mid = "";
      var possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
      for (var i = 0; i < 12; i++) {
         mid += possible.charAt(Math.floor(Math.random() * possible.length));
      }

      var submitUrl = "?mid=" + mid + "&name=" + "Jess Smith" + "&location=" + "Isabela" + "&number=" + "1234567890" + "&occupants=" + "2" + "&danger=" + "1" + "&vacant=" + "0" + "&firstaid=" + "1" + "&water=" + "1" + "&food=" + "0" + "&msg=" + "Help me please!"
      console.log(submitUrl)

      bodySentEs.className += " on";
      bodySentEs.classList.remove('off');
      bodySendEs.classList.remove("on")
      bodySendEs.className += " off"

      var url = window.location.href;
      if (url.indexOf('?') > -1){
         url = url.split("?")[0]
         url += submitUrl
      }else{
         url += submitUrl
      }
      window.location.href = url;
   },false);

   bfsos.addEventListener("click",function(e){

      var d = new Date();
      document.getElementById("dateNow").innerHTML = "March " + d.getDate() + ", " + d.getFullYear() + " @ " + d.getHours() + ":" + d.getMinutes();

      bodySent.className += " on";
      bodySent.classList.remove('off');
      bodyForm.classList.remove("on")
      bodyForm.className += " off"

      var nameInput = document.getElementById('nameInput').value
      var phoneInput = document.getElementById('phoneInput').value
      var locationInput = document.getElementById('locationInput').value
      var messageInput = document.getElementById('messageInput').value

      if (nameInput == "") {
         nameInput = "Jess Smith"
      }
      if (phoneInput == "") {
         phoneInput = "1234567890"
      }
      if (locationInput == "") {
         locationInput = "226 4th Street, Isabela"
      }
      if (messageInput == "") {
         messageInput = "I need help!"
      }

      var mid = "";
      var possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
      for (var i = 0; i < 12; i++) {
         mid += possible.charAt(Math.floor(Math.random() * possible.length));
      }

      var submitUrl = "?mid=" + mid + "&name=" + nameInput + "&location=" + locationInput + "&number=" + phoneInput + "&occupants=" + "2" + "&danger=" + "1" + "&vacant=" + "0" + "&firstaid=" + "1" + "&water=" + "1" + "&food=" + "0" + "&msg=" + messageInput
      var url = window.location.href;
      if (url.indexOf('?') > -1){
         url = url.split("?")[0]
         url += submitUrl
      }else{
         url += submitUrl
      }
      window.location.href = url;
   },false);

   bfsosEs.addEventListener("click",function(e){

      var d = new Date();
      document.getElementById("dateNowEs").innerHTML = "March " + d.getDate() + ", " + d.getFullYear() + " @ " + d.getHours() + ":" + d.getMinutes();

      bodySentEs.className += " on";
      bodySentEs.classList.remove('off');
      bodyFormEs.classList.remove("on")
      bodyFormEs.className += " off"

      var nameInput = document.getElementById('nameInputEs').value
      var phoneInput = document.getElementById('phoneInputEs').value
      var locationInput = document.getElementById('locationInputEs').value
      var messageInput = document.getElementById('messageInputEs').value

      if (nameInput == "") {
         nameInput = "Jess Smith"
      }
      if (phoneInput == "") {
         phoneInput = "1234567890"
      }
      if (locationInput == "") {
         locationInput = "226 4th Street, Isabela"
      }
      if (messageInput == "") {
         messageInput = "I need help!"
      }

      var mid = "";
      var possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
      for (var i = 0; i < 12; i++) {
         mid += possible.charAt(Math.floor(Math.random() * possible.length));
      }

      var submitUrl = "?mid=" + mid + "&name=" + nameInput + "&location=" + locationInput + "&number=" + phoneInput + "&occupants=" + "2" + "&danger=" + "1" + "&vacant=" + "0" + "&firstaid=" + "1" + "&water=" + "1" + "&food=" + "0" + "&msg=" + messageInput
      var url = window.location.href;
      if (url.indexOf('?') > -1){
         url = url.split("?")[0]
         url += submitUrl
      }else{
         url += submitUrl
      }
      window.location.href = url;
   },false);

   bhome.addEventListener("click",function(e){
      bodyIntro.className += " on";
      bodyIntro.classList.remove('off');
      bodySent.classList.remove("on")
      bodySent.className += " off"
   },false);

   bhomeEs.addEventListener("click",function(e){
      bodyIntroEs.className += " on";
      bodyIntroEs.classList.remove('off');
      bodySentEs.classList.remove("on")
      bodySentEs.className += " off"
   },false);

   bupdate.addEventListener("click",function(e){
      headEl.className += " form"
      bodyForm.className += " on";
      bodyForm.classList.remove('off');
      bodySent.classList.remove("on")
      bodySent.className += " off"
   },false);

   bupdateEs.addEventListener("click",function(e){
      headEl.className += " form"
      bodyFormEs.className += " on";
      bodyFormEs.classList.remove('off');
      bodySentEs.classList.remove("on")
      bodySentEs.className += " off"
   },false);


</script>
</html>

)=====";
